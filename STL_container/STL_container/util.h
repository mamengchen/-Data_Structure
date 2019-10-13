#pragma once

// ����ļ�����һЩͨ�ù��ߣ����� move, forward, swap��������pair
#include <cstddef>

#include "type_traits.h"

namespace mystl {
	//move
	template <class T>
	typename std::remove_reference<T>::type&& move(T&& arg) noexcept // C++11 �ؼ��ֱ�֤���������������쳣�Ͳ����쳣���
	{
		return static_cast<typename std::remove_reference<T>::type&&>(arg);
	}

	// forward
	template <class T>
	T&& forward(typename std::remove_reference<T>::type& arg) noexcept
	{
		return static_cast<T&&>(arg);
	}

	template <class T>
	T&& forward(typename std::remove_reference<T>::type&& arg) noexcept
	{
		static_assert(!std::is_lvalue_reference<T>::value, "bad forward");
		return static_cast<T&&>(arg);
	}

	// swap
	template <class Tp>
	void swap(Tp& lhs, Tp& rhs) {
		auto tmp(mystl::move(lhs));
		lhs = mystl::move(rhs);
		rhs = mystl::move(tmp);
	}

	template <class ForwardIter1,class ForwardIter2>
	ForwardIter2 swap_range(ForwardIter1 first1, ForwardIter1 last1, ForwardIter2 first2) {
		for (; first1 != last1; ++first1, (void) ++first2) {
			mystl::swap(*first1, *first2);
		}
		return first2;
	}

	template <class Tp, size_t N>
	void swap(Tp(&a)[N], Tp(&b)[N])
	{
		mystl::swap_range(a, a + N, b);
	}

	// ----------------------------------------------------------------------------------------------------------
	// pair
	//first �� second ���ֱ�ȡ����һ�����ݺ͵ڶ�������
	template <class Ty1, class Ty2>
	struct pair {
		typedef Ty1 first_type;
		typedef Ty2 second_type;

		first_type first;
		second_type second;

		// default constructiable(ȱʡ�ɹ���)
		// enable_if C++11 �µ������������к���ģ���Ƶ�����û����ͬ���͵�ʱ��Ҳ����ͨ������
		// constexpr�����������α��������������캯����һ�������κ�Ԫ�ر�constexpr���Σ���ô����˵�Ǹ��߱����� ����󵨵ؽ��ҿ��ɱ���ʱ���ܵó�����ֵ�ı��ʽȥ�Ż��ҡ���
		template <class Other1 = Ty1, class Other2 = Ty2,
			typename = typename std::enable_if<
			std::is_default_constructible<Other1>::value &&
			std::is_default_constructible<Other2>::value,void>::type>
			constexpr pair() : first(), second() 
		{}

		// implicit constructiable for this type(�����͵���ʽ�ɹ���)
		// is_convertible ���Ǵӵ�һ����������ڶ���������ת���Ƿ��ܳɹ�
		template <class U1 = Ty1, class U2 = Ty2,
			typename std::enable_if<
			std::is_copy_constructible<U1>::value &&
			std::is_copy_constructible<U2>::value &&
			std::is_convertible<const U1&, Ty1>::value &&
			std::is_convertible<const U2&, Ty2>::value,int>::type = 0>
			constexpr pair(const Ty1& a, const Ty2& b) : first(a), second(b)
		{}

		// explicit constructible for this type(�����͵���ʽ�ɹ���)
		template <class U1 = Ty1, class U2 = Ty2,
			typename std::enable_if<
			std::is_copy_constructible<U1>::value &&
			std::is_copy_constructible<U2>::value &&
			(!std::is_convertible<const U1&, Ty1>::vlaue || 
				!std::is_convertible<const U2&, Ty2>::value),int>::type = 0>
			explicit constexpr pair(const Ty1& a, const Ty2& b) : first(a), second(b)
		{}

		pair(const pair& rhs) = default;
		pair(pair&& rhs) = default;

		// implicit constructiable for other type(�������͵���ʽ�ɹ���)
		template <class Other1, class Other2,
			typename std::enable_if<
			std::is_constructible<Ty1, Other1>::value&&
			std::is_constructible<Ty2, Other2>::value&&
			std::is_convertible<Other1&&, Ty1>::value&&
			std::is_convertible<Other2&&, Ty2> ::value, int>::type = 0>
			constexpr pair(Other1 && a, Other2 && b) : first(mystl::forward<Other1>(a)),
			second(mystl::forward<Other2>(b))
		{}

		// explicit constructiable for other type(�������͵���ʽ�ɹ���)
		template <class Other1, class Other2,
			typename std::enable_if<
			std::is_constructible<Ty1, Other1>::value&&
			std::is_constructible<Ty2, Other2>::value &&
			(!std::is_convertible<Other1, Ty1>::value ||
				!std::is_convertible<Other2, Ty2>::value), int>::type = 0>
			explicit constexpr pair(Other1 && a, Other2 && b)
			: first(mystl::forward<Other1>(a)),
			second(mystl::forward<Other2>(b))
		{}

		// (implicit constructiable for other pair�����Ե���ʽ�ɹ���)
		template <class Other1,class Other2,
			typename std::enable_if<
			std::is_constructible<
	};
}