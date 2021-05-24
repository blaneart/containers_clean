/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:57:00 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:57:10 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  mymultimap.insert(TESTED_NAMESPACE::make_pair('x',100));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('y',200));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('y',350));
  mymultimap.insert(TESTED_NAMESPACE::make_pair('z',500));

  std::cout << "mymultimap.size() is " << mymultimap.size() << '\n';

  return 0;
}
