/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:01:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/21 18:02:30 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[] = {75,23,65,42,13};
  TESTED_NAMESPACE::list<int> mylist (myints,myints+5);

  std::cout << "mylist contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
