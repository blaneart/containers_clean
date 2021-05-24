/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:07:44 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:08:48 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymm;

  mymm.insert(TESTED_NAMESPACE::pair<char,int>('a',10));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('b',20));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('b',30));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('b',40));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('c',50));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('c',60));
  mymm.insert(TESTED_NAMESPACE::pair<char,int>('d',60));

  std::cout << "mymm contains:\n";
  for (char ch='a'; ch<='d'; ch++)
  {
    TESTED_NAMESPACE::pair <TESTED_NAMESPACE::multimap<char,int>::iterator, TESTED_NAMESPACE::multimap<char,int>::iterator> ret;
    ret = mymm.equal_range(ch);
    std::cout << ch << " =>";
    for (TESTED_NAMESPACE::multimap<char,int>::iterator it=ret.first; it!=ret.second; ++it)
      std::cout << ' ' << it->second;
    std::cout << '\n';
  }

  return 0;
}
