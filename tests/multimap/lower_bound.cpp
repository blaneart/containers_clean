/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:07:00 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:07:18 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;
  TESTED_NAMESPACE::multimap<char,int>::iterator it,itlow,itup;

  mymultimap.insert(TESTED_NAMESPACE::make_pair('a',10));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('b',121));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('c',1001));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('c',2002));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('d',11011));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('e',44));

  itlow = mymultimap.lower_bound ('b');  // itlow points to b
  itup = mymultimap.upper_bound ('d');   // itup points to e (not d)

  // print range [itlow,itup):
  for (it=itlow; it!=itup; ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
