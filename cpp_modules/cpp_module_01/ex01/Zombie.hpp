#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;
        int         _index;
        static int  _count;

    public:
        void    announce();
        void    setName(std::string name);
        Zombie();
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
