/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:57:09 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:57:29 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;
  TESTED_NAMESPACE::deque<int>::iterator it;

  // set some initial content:
  for (int i=1; i<10; ++i) mydeque.push_back(i);

  mydeque.resize(5);
  mydeque.resize(8,100);
  mydeque.resize(12);

  std::cout << "mydeque contains:";
  for (TESTED_NAMESPACE::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
