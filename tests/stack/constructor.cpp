/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:27:59 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 13:50:18 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<int> mydeque (3,100);          // deque with 3 elements
  TESTED_NAMESPACE::vector<int> myvector (2,200);        // vector with 2 elements
  TESTED_NAMESPACE::list<int> mylist (4,300);        // vector with 2 elements

  TESTED_NAMESPACE::stack<int> first;                    // empty stack
  TESTED_NAMESPACE::stack<int>second (mydeque);         // stack initialized to copy of deque

  TESTED_NAMESPACE::stack<int,TESTED_NAMESPACE::vector<int> > third;  // empty stack using vector
  TESTED_NAMESPACE::stack<int,TESTED_NAMESPACE::vector<int> > fourth (myvector);
  TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::list<int> > fifth(mylist);
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
  std::cout << "size of fifth: " << fifth.size() << '\n'; 

  return 0;
}
