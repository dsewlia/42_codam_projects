#include "ScavTrap.hpp"

int main()
{
    ScavTrap    d1("Scav1");
    ClapTrap    d2("clap2");

    d1.guardGate();
    for (int i = 0; i < 10; i++)
        d1.attack("random clap");
    d2.attack("dummy");
    d1.takeDamage(5);
    d1.takeDamage(5);
    for(int i = 0; i < 10; i++)
    {
        d1.takeDamage(15);
        d1.beRepaired(2);
    }
    return (0);
}