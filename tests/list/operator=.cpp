/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:51:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/21 17:58:21 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::list<int> first (3);      // list of 3 zero-initialized ints
  TESTED_NAMESPACE::list<int> second (5);     // list of 5 zero-initialized ints

  second = first;
  first = TESTED_NAMESPACE::list<int>();
  print_container(first);
  print_container(second);

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
