/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:34:54 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/21 17:51:03 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.hpp"
#include <list>
#include "../../list.hpp"
int main(void)
{
	TESTED_NAMESPACE::list<int> first;
	TESTED_NAMESPACE::list<int> second (4,100);
	TESTED_NAMESPACE::list<int> third (second.begin(),second.end());
	TESTED_NAMESPACE::list<int> fourth (third);

	print_container(second);
	print_container(third);
	print_container(fourth);
	int myints[] = {16,2,77,29};
	TESTED_NAMESPACE::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are: ";
	for (TESTED_NAMESPACE::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
	  std::cout << *it << ' ';

	std::cout << '\n';
	usleep(3000000);
	return 0;
}
