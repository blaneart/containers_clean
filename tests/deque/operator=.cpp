/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:52:25 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:52:40 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> first (3);    // deque with 3 zero-initialized ints
  TESTED_NAMESPACE::deque<int> second (5);   // deque with 5 zero-initialized ints

  second = first;
  first = TESTED_NAMESPACE::deque<int>();

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
