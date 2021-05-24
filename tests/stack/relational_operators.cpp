/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:45:29 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 14:48:44 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"

int main ()
{
  TESTED_NAMESPACE::vector<int> foov (3,100);   // three ints with a value of 100
  TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > foo (foov);   // three ints with a value of 100
  TESTED_NAMESPACE::vector<int> barv (2,200);   // two ints with a value of 200
  TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > bar (barv);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}
