/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:08:13 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/21 18:08:28 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::list<int> mylist;
  int sum (0);

  for (int i=1;i<=10;++i) mylist.push_back(i);

  while (!mylist.empty())
  {
     sum += mylist.front();
     mylist.pop_front();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
