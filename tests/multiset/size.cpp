/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:17:12 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:18:37 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multiset<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.insert(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (5);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.erase (5);
  std::cout << "3. size: " << myints.size() << '\n';

  return 0;
}
