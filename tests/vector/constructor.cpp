/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:50:40 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:03:55 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  // constructors used in the same order as described above:
  TESTED_NAMESPACE::vector<int> first;                                // empty vector of ints
  TESTED_NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
  TESTED_NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
  TESTED_NAMESPACE::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  TESTED_NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  print_container(first);
  print_container(second);
  print_container(third);
  print_container(fourth);
  std::cout << "The contents of fifth are:";
  for (TESTED_NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
