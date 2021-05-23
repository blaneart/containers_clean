/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:15:18 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:19:11 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist;
  int myint[4] =
  {
	  4, 5, 223, 42
  };

  int i = 0;
  while (i < 4)
   {

    mylist.push_back (myint[i]);
	i++;
}

  print_container(mylist);
  std::cout << "mylist stores " << mylist.size() << " numbers.\n";

  return 0;
}
