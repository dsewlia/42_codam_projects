#include <string>
#include <iostream>

class Harl
{
	private:
		typedef void (Harl::*t_complains)(void);
		t_complains	_complains[4];
		
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);
		Harl();
		~Harl();
};
