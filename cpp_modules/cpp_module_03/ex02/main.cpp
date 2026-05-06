#include "FrapTrap.hpp"

int main()
{
    FragTrap  d1("Frag1");
    ClapTrap    d2("clap2");

    d1.highFiveGuys();
    for (int i = 0; i < 10; i++)
        d1.attack("random clap");
    d2.attack("dummy");
    d1.takeDamage(5);
    d1.takeDamage(5);
    d1.highFiveGuys();
    for(int i = 0; i < 10; i++)
    {
        d1.takeDamage(15);
        d1.beRepaired(2);
    }
    return (0);
}