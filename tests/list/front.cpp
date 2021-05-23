/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:10:22 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:10:40 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist;

  mylist.push_back(77);
  mylist.push_back(22);

  // now front equals 77, and back 22

  mylist.front() -= mylist.back();

  std::cout << "mylist.front() is now " << mylist.front() << '\n';

  return 0;
}
