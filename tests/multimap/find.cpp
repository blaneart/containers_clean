/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:05:38 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:05:48 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymm;

  mymm.insert (TESTED_NAMESPACE::make_pair('x',10));
  mymm.insert (TESTED_NAMESPACE::make_pair('y',20));
  mymm.insert (TESTED_NAMESPACE::make_pair('z',30));
  mymm.insert (TESTED_NAMESPACE::make_pair('z',40));

  TESTED_NAMESPACE::multimap<char,int>::iterator it = mymm.find('x');
  mymm.erase (it);
  mymm.erase (mymm.find('z'));

  // print content:
  std::cout << "elements in mymm:" << '\n';
  std::cout << "y => " << mymm.find('y')->second << '\n';
  std::cout << "z => " << mymm.find('z')->second << '\n';

  return 0;
}
