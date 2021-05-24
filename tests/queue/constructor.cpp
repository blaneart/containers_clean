/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:33:19 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:33:33 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeck (3,100);        // deque with 3 elements
  TESTED_NAMESPACE::list<int> mylist (2,200);         // list with 2 elements

  TESTED_NAMESPACE::queue<int> first;                 // empty queue
  TESTED_NAMESPACE::queue<int> second (mydeck);       // queue initialized to copy of deque

  TESTED_NAMESPACE::queue<int,TESTED_NAMESPACE::list<int> > third; // empty queue with list as underlying container
  TESTED_NAMESPACE::queue<int,TESTED_NAMESPACE::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
