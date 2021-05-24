/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:24:34 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:24:39 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;
  TESTED_NAMESPACE::multiset<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50

  it=mymultiset.find(20);
  mymultiset.erase (it);
  mymultiset.erase (mymultiset.find(40));

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
