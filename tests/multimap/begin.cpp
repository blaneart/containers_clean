/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:55:01 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:55:11 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('a',10));
  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('b',20));
  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('b',150));

  // show content:
  for (TESTED_NAMESPACE::multimap<char,int>::iterator it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
