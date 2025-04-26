#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap dt1("DiamondOne");
    dt1.whoAmI();
    dt1.attack("TargetDummy");
    dt1.takeDamage(20);
    dt1.beRepaired(10);
    return 0;
}
