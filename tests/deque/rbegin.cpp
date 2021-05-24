/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:45 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:54:05 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque (5);  // 5 default-constructed ints

  TESTED_NAMESPACE::deque<int>::reverse_iterator rit = mydeque.rbegin();

  int i=0;
  for (rit = mydeque.rbegin(); rit!= mydeque.rend(); ++rit)
    *rit = ++i;

  std::cout << "mydeque contains:";
  for (TESTED_NAMESPACE::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
