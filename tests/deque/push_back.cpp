/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:04:46 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 15:06:46 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque;
  int myint[5] = {1, 6, 223, 63, 42};

  int i = 0;
  while (i < 5)
  {
    mydeque.push_back (myint[i]);
	i++;
  }

  std::cout << "mydeque stores " << (int) mydeque.size() << " numbers.\n";
  print_container(mydeque);
  return 0;
}
