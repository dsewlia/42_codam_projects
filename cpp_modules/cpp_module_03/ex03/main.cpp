#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap  d1("Diamond1");
    ClapTrap     d2("clap1");
    ScavTrap     d3("Scav1");
    FragTrap     d4("Frag1");

    d1.whoAmI();
    for (int i = 0; i < 10; i++)
        d1.attack("random clap");
    d2.attack("dummy");
    d3.attack("dummy");
    d4.attack("dummy");
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