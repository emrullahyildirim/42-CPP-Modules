#include <cstdlib>
#include "Harl.hpp"

int	main()
{
	Harl harl;

	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("NONE");
	return (EXIT_SUCCESS);
}