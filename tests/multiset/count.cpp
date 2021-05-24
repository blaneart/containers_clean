/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:25:07 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 17:25:16 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  int myints[]={10,73,12,22,73,73,12};
  TESTED_NAMESPACE::multiset<int> mymultiset (myints,myints+7);

  std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";

  return 0;
}
