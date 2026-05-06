/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:45:20 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 13:45:38 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <limits>
#include "Contact.hpp"

class   Phonebook
{
    private:
        Contact					_contacts[8];
		static int				_count;
        std::string             _formatter(std::string str);

    public:
        void    _ADD();
        void    _SEARCH();
        void    _EXIT();

        Phonebook();
};