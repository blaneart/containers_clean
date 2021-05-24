/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:23:48 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:23:59 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;

  TESTED_NAMESPACE::multiset<int>::value_compare mycomp = mymultiset.value_comp();

  for (int i=0; i<7; i++) mymultiset.insert(i);

  std::cout << "mymultiset contains:";

  int highest = *mymultiset.rbegin();
  TESTED_NAMESPACE::multiset<int>::iterator it = mymultiset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*it++,highest) );

  std::cout << '\n';

  return 0;
}
