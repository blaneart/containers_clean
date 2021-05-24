/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:01:05 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:01:16 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  // insert some values:
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('a',10));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('b',20));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('b',30));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('c',40));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('d',50));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('d',60));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('e',70));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('f',80));

  TESTED_NAMESPACE::multimap<char,int>::iterator it = mymultimap.find('b');

  mymultimap.erase (it);                     // erasing by iterator (1 element)

  mymultimap.erase ('d');                    // erasing by key (2 elements)

  it=mymultimap.find ('e');
  mymultimap.erase ( it, mymultimap.end() ); // erasing by range

  // show content:
  for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
