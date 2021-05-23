/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:13:47 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:14:06 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist (2,100);         // two ints with a value of 100
  mylist.push_front (200);
  mylist.push_front (300);

  std::cout << "mylist contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
  return 0;
}
