#include "Harp.hpp"

Harl::Harl()
{
	_complains[0] = &Harl::debug;
	_complains[1] = &Harl::info;
	_complains[2] = &Harl::warning;
	_complains[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "\nI think I deserve to have some extra bacon for free. I've been comming for years, whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;
	for(i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	switch(i)
	{
		case 0:
			(this->*_complains[0])();

		case 1:
			(this->*_complains[1])();

		case 2:
			(this->*_complains[2])();

		case 3:
			(this->*_complains[3])();
			break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break ;
	}
}
