/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:06:13 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:06:30 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymm;

  mymm.insert(TESTED_NAMESPACE::make_pair('x',50));
  mymm.insert(TESTED_NAMESPACE::make_pair('y',100));
  mymm.insert(TESTED_NAMESPACE::make_pair('y',150));
  mymm.insert(TESTED_NAMESPACE::make_pair('y',200));
  mymm.insert(TESTED_NAMESPACE::make_pair('z',250));
  mymm.insert(TESTED_NAMESPACE::make_pair('z',300));

  for (char c='x'; c<='z'; c++)
  {
    std::cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
    TESTED_NAMESPACE::multimap<char,int>::iterator it;
    for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
      std::cout << ' ' << (*it).second;
    std::cout << '\n';
  }

  return 0;
}
