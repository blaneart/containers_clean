/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:50:12 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 18:42:03 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{

  // constructors used in the same order as described above:
  TESTED_NAMESPACE::deque<int> first;                                // empty deque of ints
  TESTED_NAMESPACE::deque<int> second (4,100);                       // four ints with value 100
  TESTED_NAMESPACE::deque<int> third (second.begin(),second.end());  // iterating through second
  TESTED_NAMESPACE::deque<int> fourth (third);                       // a copy of third

  // the iterator constructor can be used to copy arrays:
  int myints[] = {16,2,77,29};
  TESTED_NAMESPACE::deque<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (TESTED_NAMESPACE::deque<int>::iterator it = fifth.begin(); it!=fifth.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
