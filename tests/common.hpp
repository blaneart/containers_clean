/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:36:19 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/21 17:58:26 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP
# include <iostream>
# include <unistd.h>
# include <list>
# include "../list.hpp"

template <class T>
void print_container(T container)
{
	std::cout << "Container's values:" << std::endl;
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << std::endl;

}

#endif
