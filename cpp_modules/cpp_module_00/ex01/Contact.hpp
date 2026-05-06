/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:41:46 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 14:43:47 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cctype"

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _darkestSecret;
        std::string _phoneNumber;

    public:
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
		void		clear();
        
		Contact();
		~Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
};
    