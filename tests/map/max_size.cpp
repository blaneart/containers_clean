/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:45:18 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:45:32 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int i;
  TESTED_NAMESPACE::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";

  return 0;
}
