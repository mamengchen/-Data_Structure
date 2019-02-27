#include<stdio.h>
#include<assert.h>



void Insetsort(int * arr, size_t n) {
	assert(arr);
	for (size_t index = 0; index < n; ++index) {
		size_t tmp = arr[index];		//记录每次无序数组的第一个元素
		int pos = index - 1;			
		while (pos >= 0 && arr[pos] > tmp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = tmp;
	}
}


//其实还是把左边当成有序数，只是使用二分查找来查找位置而已

void TwoInsetsort(int * arr, int n) {
	int left, right, num;
	int middle, j, i;
	for (i = 1; i < n; i++) {
		left = 0;	//准备
		right = i - 1;
		num = arr[i];
		while (right >= left) {
			middle = (left + right) / 2;		//指向已排序好的中间位置
			if (num < arr[middle]) {
				//即将插入的元素应当在左区间
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		for (j = i - 1; j >= left; j--) {
			arr[j + 1] = arr[j];
		}
		arr[left] = num;		//插入
	}
}

//希尔排序就是把它分为几组，
void ShellSort(int* arr, size_t n) {
	int gap = n / 3 + 1;
	for (size_t index = gap; index < n; index++) {
		size_t tmp = arr[index];
		int pos = index - gap;
		while (pos >= 0 && arr[pos] > tmp) {
			arr[pos + gap] = arr[pos];
			pos -= gap;
		}
		arr[pos + gap] = tmp;
	}
}

//冒泡排序
void PopSort(int* arr, size_t n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}

//选择排序
void selectSort(int * arr, size_t n) {
	int min;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			min = i;
			if (arr[min] > arr[j]) {
				min = j;
			}

			tmp = arr[min];
			arr[min] = arr[j];
			arr[j] = tmp;
		}
	}
}

//选择排序
void selectSort(int A[], int len) {
	int i, j, k;
	for (int i = 0; i < len; i++) {
		k = i;
		for (j = i + 1; j < len; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		if (i != k) {
			A[i] = A[i] + A[k];
			A[k] = A[i] - A[k];
			A[i] = A[i] - A[k];
		}
	}
}




//快速排序：
int GetMidNum(int* a, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	
	if (a[begin] > a[mid]) {
		if (a[mid] > a[end]) {
			return mid;
		}
		else if (a[begin] > a[end]) {
			return end;
		}
		else {
			return begin;
		}
	}
	else {
		if (a[begin] > a[end]) {
			return begin;
		}
		else if (a[mid] < a[end]) {
			return end;
		}
		else {
			return mid;
		}
	}
}
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//1.左右指针法
//	实现思路：找出一个枢纽（或区间开始的元素，或区间结束的元素），从左边开始进行遍历
//	找到一个大于枢纽的值停下来，然后从右边找小于枢纽的值，然后停下来，将左右找到值进行交换
int PartSort1(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}
	int key = a[end];
	int left = begin;
	int right = end - 1;
	//左边找比key大的值，找到就停下
	//右边找比key小的值，找到就停下
	//两者交换
	while (left < right) {
		while (left < right && a[left] <= key) {
			++left;
		}
		while (left < right && a[right] >= key) {
			--right;
		}
		swap(a[left], a[right]);
	}
	//如果left一直没有找到大于key的值，会停下来
	if (a[left] > a[end]) {
		swap(a[left], a[end]);
	}
	return left;
}
//2.挖坑法：类似于左右指针法
int PartSort2(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}

	int key = a[end];
	int left = begin;
	int right = end;
	while (left < right) {
		while (left < right && a[left] <= key) {
			++left;
		}
		a[right] = a[left];//将找到的值填到预留的坑
		while (left < right && a[right] >= key) {
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

//3.前后指针法：
//	实现思路：开始让prev指向begin的前一个位置，cur指向begin位置，从左向右
//	当找到cur指向的值小于枢纽值，将prev后移，然后prev所指向的值与cur所指向
//	的值进行交换。
int PartSort3(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}
	int key = a[end];
	int prev = begin - 1;
	int cur = begin;
	while (cur < end) {
		if (a[cur] < key && ++prev != cur) {
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	swap(a[++prev], a[end]);
	return prev;
}

void QuickSort(int* a, int begin, int end) {
	if (begin < end) {
		int key = PartSort1(a, begin, end);
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
}


//快排适合那些大数据，但是数据少的话对栈的开销是比较大的，再少数量的时候换为插入排序
void QuickSortOP(int* a, int begin, int end) {
	if (end - begin > 13) {
		int key = PartSort3(a, begin, end);
		QuickSortOP(a, begin, key - 1);
		QuickSortOP(a, key + 1, end);
	}
	else {
		Insetsort(a + begin, end - begin + 1);
	}
}
int main()
{
	int arr[] = { 5,2,3,1,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	TwoInsetsort(arr, sz);
	return 0;
}