/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:15:28 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:16:01 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[] = {77,16,2,30,30};
  TESTED_NAMESPACE::multiset<int> mymultiset (myints,myints+5);

  std::cout << "mymultiset contains:";
  for (TESTED_NAMESPACE::multiset<int>::reverse_iterator rit=mymultiset.rbegin(); rit!=mymultiset.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}
