/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:18:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 15:19:12 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) mydeque.push_back(i);

  // erase the 6th element
  mydeque.erase (mydeque.begin()+5);

  // erase the first 3 elements:
  mydeque.erase (mydeque.begin(),mydeque.begin()+3);

  std::cout << "mydeque contains:";
  for (TESTED_NAMESPACE::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
