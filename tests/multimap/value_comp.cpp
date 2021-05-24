/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:04:56 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:05:12 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  mymultimap.insert(TESTED_NAMESPACE::make_pair('x',101));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('y',202));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('y',252));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('z',303));

  std::cout << "mymultimap contains:\n";

  TESTED_NAMESPACE::pair<char,int> highest = *mymultimap.rbegin();          // last element

  TESTED_NAMESPACE::multimap<char,int>::iterator it = mymultimap.begin();
  do {
    std::cout << (*it).first << " => " << (*it).second << '\n';
  } while ( mymultimap.value_comp()(*it++, highest) );

  return 0;
}
