/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:02:30 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 15:02:39 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;

  mydeque.push_front(77);
  mydeque.push_back(20);

  mydeque.front() -= mydeque.back();

  std::cout << "mydeque.front() is now " << mydeque.front() << '\n';

  return 0;
}
