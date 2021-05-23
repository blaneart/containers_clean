/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:46:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:47:34 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( TESTED_NAMESPACE::pair<char,int>('a',100) );
  mymap.insert ( TESTED_NAMESPACE::pair<char,int>('z',200) );

  TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( TESTED_NAMESPACE::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  TESTED_NAMESPACE::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, TESTED_NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, TESTED_NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  TESTED_NAMESPACE::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
