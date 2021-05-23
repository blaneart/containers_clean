/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:38:41 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 17:38:58 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[]= {17,89,7,14};
  TESTED_NAMESPACE::list<int> mylist (myints,myints+4);

  mylist.remove(89);

  std::cout << "mylist contains:";
  for (TESTED_NAMESPACE::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
