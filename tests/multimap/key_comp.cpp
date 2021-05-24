/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:03:55 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:04:18 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  TESTED_NAMESPACE::multimap<char,int>::key_compare mycomp = mymultimap.key_comp();

  mymultimap.insert (TESTED_NAMESPACE::make_pair('a',100));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('b',200));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('b',211));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('c',300));

  std::cout << "mymultimap contains:\n";

  char highest = mymultimap.rbegin()->first;     // key value of last element

  TESTED_NAMESPACE::multimap<char,int>::iterator it = mymultimap.begin();
  do {
    std::cout << (*it).first << " => " << (*it).second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';

  return 0;
}
