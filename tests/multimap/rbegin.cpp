/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:55:37 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:55:55 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  mymultimap.insert (TESTED_NAMESPACE::make_pair('x',10));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('y',20));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('y',150));
  mymultimap.insert (TESTED_NAMESPACE::make_pair('z',9));

  // show content:
  TESTED_NAMESPACE::multimap<char,int>::reverse_iterator rit;
  for (rit=mymultimap.rbegin(); rit!=mymultimap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

  return 0;
}
