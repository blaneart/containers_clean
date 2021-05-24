/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:31:15 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:31:30 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

typedef TESTED_NAMESPACE::multiset<int>::iterator It;  // aliasing the iterator type used

int main ()
{
  int myints[]= {77,30,16,2,30,30};
  TESTED_NAMESPACE::multiset<int> mymultiset (myints, myints+6);  // 2 16 30 30 30 77

  TESTED_NAMESPACE::pair<It,It> ret = mymultiset.equal_range(30); //      ^        ^

  mymultiset.erase(ret.first,ret.second);

  std::cout << "mymultiset contains:";
  for (It it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
