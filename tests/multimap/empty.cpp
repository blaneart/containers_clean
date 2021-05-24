/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:56:24 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:56:37 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::multimap<char,int> mymultimap;

  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('b',101));
  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('b',202));
  mymultimap.insert (TESTED_NAMESPACE::pair<char,int>('q',505));

  while (!mymultimap.empty())
  {
     std::cout << mymultimap.begin()->first << " => ";
     std::cout << mymultimap.begin()->second << '\n';
     mymultimap.erase(mymultimap.begin());
  }

  return 0;
}
