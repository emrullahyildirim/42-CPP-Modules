#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap alpha("Emrullah");
	ClapTrap beta("Esat");

	std::cout << "\n--- ROUND 1 ---" << std::endl;
	alpha.attack("Beta");
	beta.takeDamage(5);

	std::cout << "\n--- ROUND 2 ---" << std::endl;
	beta.attack("Alpha");
	alpha.takeDamage(3);

	std::cout << "\n--- REPAIR TIME ---" << std::endl;
	alpha.beRepaired(4);
	beta.beRepaired(2);

	std::cout << "\n--- OUT OF ENERGY TEST ---" << std::endl;
	for (int i = 0; i < 11; ++i)
		alpha.attack("TargetDummy");

	std::cout << "\n--- DEATH TEST ---" << std::endl;
	beta.takeDamage(100);
	beta.attack("Alpha");
	beta.beRepaired(10);  

	std::cout << "\n--- END ---" << std::endl;
	return 0;
}
