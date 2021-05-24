/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:21:20 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:21:48 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[]={19,72,4,36,20,20};
  TESTED_NAMESPACE::multiset<int> first (myints,myints+3);     // 4,19,72
  TESTED_NAMESPACE::multiset<int> second (myints+3,myints+6);  // 20,20,36

  first.swap(second);

  std::cout << "first contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (TESTED_NAMESPACE::multiset<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
