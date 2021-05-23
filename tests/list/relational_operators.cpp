/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:44:39 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 17:47:23 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
int main ()
{
  TESTED_NAMESPACE::list<int> a;
  TESTED_NAMESPACE::list<int> b;
  TESTED_NAMESPACE::list<int> c;

  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);
  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";

  return 0;
}
