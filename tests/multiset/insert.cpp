/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:20:02 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:20:11 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;
  TESTED_NAMESPACE::multiset<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) mymultiset.insert(i*10);  // 10 20 30 40 50

  it=mymultiset.insert(25);

  it=mymultiset.insert (it,27);    // max efficiency inserting
  it=mymultiset.insert (it,29);    // max efficiency inserting
  it=mymultiset.insert (it,24);    // no max efficiency inserting (24<29)

  int myints[]= {5,10,15};
  mymultiset.insert (myints,myints+3);

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
