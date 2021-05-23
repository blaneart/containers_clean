/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:22:57 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:24:34 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::vector<int> myvector;
  int myint[4] = {4, 15, 42, 5};
  int i = 0;

  while (i < 4)
  {

    myvector.push_back (myint[i]);
	i++;
  }
  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  print_container(myvector);
  return 0;
}
