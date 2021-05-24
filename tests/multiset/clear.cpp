/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:22:18 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:22:36 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;

  mymultiset.insert (11);
  mymultiset.insert (42);
  mymultiset.insert (11);

  std::cout << "mymultiset contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mymultiset.clear();
  mymultiset.insert (200);
  mymultiset.insert (100);

  std::cout << "mymultiset contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
