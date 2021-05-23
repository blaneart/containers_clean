/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:19:35 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:19:46 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist;
  int sum (0);
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  while (!mylist.empty())
  {
    sum+=mylist.back();
    mylist.pop_back();
  }

  std::cout << "The elements of mylist summed " << sum << '\n';

  return 0;
}
