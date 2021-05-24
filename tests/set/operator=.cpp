/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:02:49 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 16:05:11 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[]={ 12,82,37,64,15 };
  TESTED_NAMESPACE::set<int> first (myints,myints+5);   // set with 5 ints
  TESTED_NAMESPACE::set<int> second;                    // empty set

  second = first;                          // now second contains the 5 ints
  first = TESTED_NAMESPACE::set<int>();                 // and first is empty
  //
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
