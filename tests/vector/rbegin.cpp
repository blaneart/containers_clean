/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:11:12 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:12:37 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  TESTED_NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
