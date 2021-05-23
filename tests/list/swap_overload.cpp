/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_overload.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:48:13 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 17:48:29 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> foo (3,100);   // three ints with a value of 100
  TESTED_NAMESPACE::list<int> bar (5,200);   // five ints with a value of 200

  std::swap(foo,bar);

  std::cout << "foo contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
