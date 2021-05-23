/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:31:49 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 17:33:36 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> first (3,100);   // three ints with a value of 100
  TESTED_NAMESPACE::list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  std::cout << "first contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=second.begin(); it!=second.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
