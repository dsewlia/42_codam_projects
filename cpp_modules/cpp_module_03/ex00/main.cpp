#include "ClapTrap.hpp"

int main()
{
    ClapTrap    d1("clap1");
    ClapTrap    d2("clap2");

    for (int i = 0; i < 10; i++)
        d1.attack("random clap");
    d1.takeDamage(5);
    d1.takeDamage(5);
    for(int i = 0; i < 10; i++)
    {
        d1.takeDamage(2);
        d1.beRepaired(2);
    }
    return (0);
}