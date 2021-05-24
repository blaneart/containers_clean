/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:30:27 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:30:39 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;
  TESTED_NAMESPACE::multiset<int>::iterator itlow,itup;

  for (int i=1; i<8; i++) mymultiset.insert(i*10); // 10 20 30 40 50 60 70

  itlow = mymultiset.lower_bound (30);             //       ^
  itup = mymultiset.upper_bound (40);              //             ^

  mymultiset.erase(itlow,itup);                    // 10 20 50 60 70

  std::cout << "mymultiset contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
