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
	std::cout << "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\nI think I deserve to have some extra bacon for free. I've been comming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "\nThis is unacceptable! I want to speak to the manager now." << std::endl;
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
	if (i < 4)
		(this->*_complains[i])();
	else
	{
		std::cout << "\nHarl is limited and doesn't know what to say at \"" << level << "\" level\n" << std::endl;
	}
}
