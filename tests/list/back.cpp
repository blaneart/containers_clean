/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:11:14 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:11:37 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist;

  mylist.push_back(10);

  while (mylist.back() != 0)
  {
    mylist.push_back ( mylist.back() -1 );
  }

  std::cout << "mylist contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
