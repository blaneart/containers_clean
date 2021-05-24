/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:02:05 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:02:48 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> foo,bar;

  foo.insert(TESTED_NAMESPACE::make_pair('x',100));
  foo.insert(TESTED_NAMESPACE::make_pair('y',200));

  bar.insert(TESTED_NAMESPACE::make_pair('a',11));
  bar.insert(TESTED_NAMESPACE::make_pair('b',22));
  bar.insert(TESTED_NAMESPACE::make_pair('a',55));

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (TESTED_NAMESPACE::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  std::cout << "bar contains:\n";
  for (TESTED_NAMESPACE::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
