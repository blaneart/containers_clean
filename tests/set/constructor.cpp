/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:26:40 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/24 15:55:45 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"


bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  TESTED_NAMESPACE::set<int> first;                           // empty set of ints

  int myints[]= {10,20,30,40,50};
  TESTED_NAMESPACE::set<int> second (myints,myints+5);        // range

  TESTED_NAMESPACE::set<int> third (second);                  // a copy of second

  TESTED_NAMESPACE::set<int> fourth (second.begin(), second.end());  // iterator ctor.

  TESTED_NAMESPACE::set<int,classcomp> fifth;                 // class as Compare

  bool(*fn_pt)(int,int) = fncomp;
  TESTED_NAMESPACE::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
  print_container(first);
  print_container(second);
  print_container(third);
  print_container(fourth);
  print_container(fifth);
  print_container(sixth);
  return 0;
}
