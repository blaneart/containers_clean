/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:03:10 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:03:23 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;
  TESTED_NAMESPACE::multimap<char,int>::iterator it;

  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('b',80));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('b',120));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('q',360));

  std::cout << "mymultimap contains:\n";
  for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  mymultimap.clear();

  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('a',11));
  mymultimap.insert(TESTED_NAMESPACE::pair<char,int>('x',22));

  std::cout << "mymultimap contains:\n";
  for (it=mymultimap.begin(); it != mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
