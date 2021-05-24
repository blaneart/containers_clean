/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator[].cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:59:39 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:59:53 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque (10);   // 10 zero-initialized elements
  TESTED_NAMESPACE::deque<int>::size_type sz = mydeque.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) mydeque[i]=i;

  // reverse order of elements using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = mydeque[sz-1-i];
    mydeque[sz-1-i]=mydeque[i];
    mydeque[i]=temp;
  }

  // print content:
  std::cout << "mydeque contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << mydeque[i];
  std::cout << '\n';

  return 0;
}
