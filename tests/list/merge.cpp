/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:41:37 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 17:41:50 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
  TESTED_NAMESPACE::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (TESTED_NAMESPACE::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
