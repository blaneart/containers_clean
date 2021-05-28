/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:01:31 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/28 16:22:19 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{

	//PAIR
	template <class Key, class T>
	struct pair
	{
		Key	first;
		T	second;

		typedef	Key				first_type;
		typedef T				second_type;
		pair():
		first(), second()
		{}
		template<class U, class V>
		pair(const pair<U,V>& pr):
		first(pr.first), second(pr.second)
		{}
		pair (const first_type& a, const second_type& b):
		first(a), second(b)
		{}
		pair& operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};
	//Relational operators
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	}
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	}
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
			return pair<T1,T2>(x, y);
	}
	
	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if<true, IsTrue> {
		typedef IsTrue type;
	};

	template <bool flag, class IsTrue, class IsFalse>
	struct choose;

	template <class IsTrue, class IsFalse>
	struct choose<true, IsTrue, IsFalse> {
	   typedef IsTrue type;
	};

	template <class IsTrue, class IsFalse>
	struct choose<false, IsTrue, IsFalse> {
	   typedef IsFalse type;
	};

		template <class Ite1, class Ite2>
		bool equal (Ite1 first, Ite1 last, Ite2 first2)
		{
			while (first != last)
			{
				if (*first != *first2)
					return false;
				++first;
				++first2;
			}
			return true;
		}

		template <class Ite1, class Ite2>
		bool lexicographical_compare(Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
		{
			while (first1 != last1 && first2 != last2 && *first1 == *first2)
			{
				++first1; ++first2;
			}
			if (first1 == last1)
				return (first2 != last2);
			else if (first2 == last2)
				return (false);
			return (*first1 < *first2);
		}
}

#endif
