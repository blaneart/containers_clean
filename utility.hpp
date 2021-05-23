/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:01:31 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:03:02 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
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
