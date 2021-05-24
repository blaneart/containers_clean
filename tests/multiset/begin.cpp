/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:14:41 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:14:55 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[] = {42,71,71,71,12};
  TESTED_NAMESPACE::multiset<int> mymultiset (myints,myints+5);

  TESTED_NAMESPACE::multiset<int>::iterator it;

  std::cout << "mymultiset contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
