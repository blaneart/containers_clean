/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:58:51 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:58:59 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;
  int sum (0);

  for (int i=1;i<=10;i++) mydeque.push_back(i);

  while (!mydeque.empty())
  {
     sum += mydeque.front();
     mydeque.pop_front();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
