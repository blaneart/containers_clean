/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:13:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:14:21 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[]={ 19,81,36,36,19 };
  TESTED_NAMESPACE::multiset<int> first (myints,myints+5);   // multiset with 5 ints
  TESTED_NAMESPACE::multiset<int> second;                    // empty multiset

  second=first;                                 // now second contains the 5 ints
  first=TESTED_NAMESPACE::multiset<int>();                   // and first is empty

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
  return 0;
}
