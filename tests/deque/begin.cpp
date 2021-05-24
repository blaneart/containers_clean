/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:08 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:53:22 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;

  for (int i=1; i<=5; i++) mydeque.push_back(i);

  std::cout << "mydeque contains:";

  TESTED_NAMESPACE::deque<int>::iterator it = mydeque.begin();

  while (it != mydeque.end())
    std::cout << ' ' << *it++;

  std::cout << '\n';

  return 0;
}
