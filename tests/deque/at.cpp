/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:00:33 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 15:01:54 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::deque<unsigned> mydeque (10);   // 10 zero-initialized unsigneds

  // assign some values:
  for (unsigned i=0; i<mydeque.size(); i++)
    mydeque.at(i)=i;

  std::cout << "mydeque contains:";
  for (unsigned i=0; i<mydeque.size(); i++)
    std::cout << ' ' << mydeque.at(i);

  std::cout << '\n';

  try
  {
	  mydeque.at(100);
  }
  catch (const std::exception& e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
			  }
  return 0;
}
