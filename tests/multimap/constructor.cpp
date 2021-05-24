/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:50:45 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:52:47 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;
  TESTED_NAMESPACE::multimap<char,int>::iterator it;

  // first insert function version (single parameter):
  mymultimap.insert ( TESTED_NAMESPACE::pair<char,int>('a',100) );
  mymultimap.insert ( TESTED_NAMESPACE::pair<char,int>('z',150) );
  it=mymultimap.insert ( TESTED_NAMESPACE::pair<char,int>('b',75) );

  // second insert function version (with hint position):
  mymultimap.insert (it, TESTED_NAMESPACE::pair<char,int>('c',300));  // max efficiency inserting
  mymultimap.insert (it, TESTED_NAMESPACE::pair<char,int>('z',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  TESTED_NAMESPACE::multimap<char,int> anothermultimap;
  anothermultimap.insert(mymultimap.begin(),mymultimap.find('c'));

  // showing contents:
  std::cout << "mymultimap contains:\n";
  for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  std::cout << "anothermultimap contains:\n";
  for (it=anothermultimap.begin(); it!=anothermultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
