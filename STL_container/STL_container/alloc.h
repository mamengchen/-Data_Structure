#pragma once

#include <new>
#include <cstddef>
#include <cstdio>

namespace mystl {
	union FreeList
	{
		union FreeList* next;
		char data[1];
	};

	enum
	{
		EAlign128 = 8,
		EAlign256 = 16,
		EAlign512 = 32,
		EAlign1024 = 64,
		EAlign2048 = 128,
		EAlign4096 = 256
	};

	enum { ESmallObjectBytes = 4096};
	enum { EFreeListsNumber = 56 };

	//当分配的内存过大的时候使用std::malloc,std::free
	class alloc {
	private:
		static char* start_free;
		static char* end_free;
		static size_t heap_size;

		static FreeList* free_list[EFreeListsNumber];
	public:
		static void* allocate(size_t n);
		static void deallocate(void* p, size_t n);
		static void* reallocate(void* p, size_t old_size, size_t new_size);

	private:
		static size_t M_align(size_t bytes);
		static size_t M_round_up(size_t bytes);
		static size_t M_freelist_index(size_t bytes);
		static void* M_refill(size_t n);
		static char* M_chunk_alloc(size_t size, size_t& nobj);
	};

	char* alloc::start_free = nullptr;
	char* alloc::end_free = nullptr;
	size_t alloc::heap_size = 0;

	FreeList* alloc::free_list[EFreeListsNumber] = { nullptr };

	//bytes 对应上调大小
	inline size_t alloc::M_align(size_t bytes) {
		if (bytes <= 512) {
			return bytes <= 256 ? bytes <= 128 ? EAlign128 : EAlign256 : EAlign512;
		}
		return bytes <= 2048 ? bytes <= 1024 ? EAlign1024 : EAlign2048 : EAlign4096;
	}

	// 将 bytes 上调至对应区间大小
	inline size_t alloc::M_round_up(size_t bytes) {
		return ((bytes + M_align(bytes) - 1) & ~(M_align(bytes) - 1));
	}

	//根据区块大小，选择第 n 个free lists
	inline size_t alloc::M_freelist_index(size_t bytes) {
		if (bytes <= 512) {
			return bytes <= 256 ? bytes <= 128 ?
				((bytes + EAlign128 - 1) / EAlign128 - 1) :
				(15 + (bytes + EAlign256 - 129) / EAlign256) :
				(23 + (bytes + EAlign512 - 257) / EAlign512);
		}
		return bytes <= 2048
			? bytes <= 1024 ? (31 + (bytes + EAlign1024 - 513) / EAlign1024) :
			(39 + (bytes + EAlign2048 - 1025) / EAlign2048)
			: (47 + (bytes + EAlign4096 - 2049) / EAlign4096);
	}

	// 重新填充 free list
	void* alloc::M_refill(size_t n) {
		size_t nblock = 10;
		char* c = M_chunk_alloc(n, nblock);
		FreeList* my_free_list;
		FreeList* result, * cur, * next;
		// 如果只有一个区块，就把这个区块返回给调用者，free list 没有增加新节点
		if (nblock == 1) {
			return c;
		}
		// 否则把一个区块给调用者，剩下的纳入 free list 作为新节点
		my_free_list = free_list[M_freelist_index(n)];
		result = (FreeList*)c;
		my_free_list = next = (FreeList*)(c + n);
		for (size_t i = 1;; ++i) {
			cur = next;
			next = (FreeList*)((char*)next + n);
			if (nblock - 1 == i) {
				cur->next = nullptr;
				break;
			}
			else {
				cur->next = next;
			}
		}
		return result;
	}

	// 从内存池中取空间给 free list 使用，条件不允许时，会调整nblock
	char* alloc::M_chunk_alloc(size_t size, size_t& nblock) {
		char* result;
		size_t need_bytes = size * nblock;
		size_t pool_bytes = end_free - start_free;

		// 如果内存池剩余大小完全满足需求量，返回它
		if (pool_bytes >= need_bytes) {
			result = start_free;
			start_free += need_bytes;
			return result;
		}

		// 如果内存池剩余大小不能完全满足需求量，但至少可以分配一块或一块以上的空间
		else if (pool_bytes >= size) {
			nblock = pool_bytes / size;
			need_bytes = size * nblock;
			result = start_free;
			start_free += need_bytes;
			return result;
		}

		// 如果内存池剩余大小连一个区块都无法满足
		else {
			if (pool_bytes > 0) {
				// 如果内存池还有剩余，把剩余的空间加入到 free list 中
				FreeList* my_free_list = free_list[M_freelist_index(pool_bytes)];
				((FreeList*)start_free)->next = my_free_list;
				my_free_list = (FreeList*)start_free;
			}

			// 申请 heap 空间
			size_t bytes_to_get = (need_bytes << 1) + M_round_up(heap_size >> 4);
			start_free = (char*)std::malloc(bytes_to_get);
			if (!start_free) {
				FreeList* my_free_list, * p;
				// 试着查找有无未用区块，且区块足够大的 free list
				for (size_t i = size; i <= ESmallObjectBytes; i += M_align(i)) {
					my_free_list = free_list[M_freelist_index(i)];
					p = my_free_list;
					if (p) {
						my_free_list = p->next;
						start_free = (char*)p;
						end_free = start_free + i;
						return M_chunk_alloc(size, nblock);
					}
				}
				std::printf("out of memory");
				end_free = nullptr;
				throw std::bad_alloc();
			}
			end_free = start_free + bytes_to_get;
			heap_size += bytes_to_get;
			return M_chunk_alloc(size, nblock);
		}
	}




	//分配大小为 n 的空间，n > 0
	inline void* alloc::allocate(size_t n) {
		FreeList* my_free_list;
		FreeList* result;
		if (n > static_cast<size_t>(ESmallObjectBytes))
			return std::malloc(n);
		my_free_list = free_list[M_freelist_index(n)];
		result = my_free_list;
		if (result == nullptr) {
			void* r = M_refill(M_round_up(n));
			return r;
		}
		my_free_list = result->next;
		return result;
	}

	// 释放 p 指向的大小为 n 的空间，p 不能为 0
	inline void alloc::deallocate(void* p, size_t n) {
		if (n > static_cast<size_t>(ESmallObjectBytes)) {
			std::free(p);
			return;
		}
		FreeList* q = reinterpret_cast<FreeList*>(p);
		FreeList* my_free_list;
		my_free_list = free_list[M_freelist_index(n)];
		q->next = my_free_list;
		my_free_list = q;
	}

	// 重新分配空间，接受三个参数，参数一为指向新空间的指针，参数二为原来空间的大小，参数三为申请空间的大小
	inline void* alloc::reallocate(void* p, size_t old_size, size_t new_size) {
		deallocate(p, old_size);
		p = allocate(new_size);
		return p;
	}
}