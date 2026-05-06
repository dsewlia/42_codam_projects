#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        void    announce(void);
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
