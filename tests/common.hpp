/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:36:19 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/23 18:36:19 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP
# include <iostream>
# include <unistd.h>
# include <list>
# include <string>
# include <cctype>
# include <cmath>
# include "../list.hpp"


#include "../vector.hpp"
#include <vector>

#include "../map.hpp"
#include <map>
template <class T>
void print_container(T container)
{
	std::cout << "Container's values:" << std::endl;
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << std::endl;

}

#endif
