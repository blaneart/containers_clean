/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:23:06 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:23:21 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;

  for (int i=0; i<5; i++) mymultiset.insert(i);

  TESTED_NAMESPACE::multiset<int>::key_compare mycomp = mymultiset.key_comp();

  std::cout << "mymultiset contains:";

  int highest = *mymultiset.rbegin();

  TESTED_NAMESPACE::multiset<int>::iterator it = mymultiset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*it++,highest) );

  std::cout << '\n';

  return 0;
}
