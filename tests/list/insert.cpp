/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:20:21 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 16:58:08 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::list<int> mylist;
  TESTED_NAMESPACE::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i)
  {
	 mylist.push_back(i); // 1 2 3 4 5
	 std::cout << i << std::endl;
  }
  print_container(mylist);
  it = mylist.begin();
  ++it;       // it points now to number 2           ^

  mylist.insert (it,10);
  // std::cout << "f" << it._prev->data << std::endl;
  // std::cout << "a" << *(--it) << std::endl;// 1 10 2 3 4 5
  // std::cout << "a" << *(++it) << std::endl;// 1 10 2 3 4 5
  print_container(mylist);
  // "it" still points to number 2                      ^
    // std::cout << *it << std::endl;
  mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
  print_container(mylist);
  --it;       // it points now to the second 20            ^

  TESTED_NAMESPACE::list<int> myvector (2,30);
  mylist.insert(it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
