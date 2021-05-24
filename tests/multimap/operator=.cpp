/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:53:25 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:54:41 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> foo,bar;

  foo.insert(TESTED_NAMESPACE::make_pair('x',32));
  foo.insert(TESTED_NAMESPACE::make_pair('y',64));
  foo.insert(TESTED_NAMESPACE::make_pair('y',96));
  foo.insert(TESTED_NAMESPACE::make_pair('z',128));

  bar = foo;                  // bar now contains 4 ints
  foo.clear();                // and first is now empty

  std::cout << "Size of foo: " << foo.size() << '\n';
  std::cout << "Size of bar: " << bar.size() << '\n';
  return 0;
}
