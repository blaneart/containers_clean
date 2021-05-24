/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:16:35 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:16:48 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> mymultiset;

  mymultiset.insert(10);
  mymultiset.insert(20);
  mymultiset.insert(10);

  std::cout << "mymultiset contains:";
  while (!mymultiset.empty())
  {
     std::cout << ' ' << *mymultiset.begin();
     mymultiset.erase(mymultiset.begin());
  }
  std::cout << '\n';

  return 0;
}
