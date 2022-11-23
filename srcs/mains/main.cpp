#include <iostream>
#include <cstdlib>
#include "main_constructors.cpp"

static void	showIndexes() {
	std::cout << "List of tests:" << std::endl;
	std::cout << "1: Constructors" << std::endl << std::endl;
}

int	main() {
	std::string	idx;

	std::cout << "Please enter the number of the test to execute (0 to show the list, \"exit\" to exit): ";
	while (std::getline(std::cin, idx)) {
		if (idx.compare("exit") == 0)
			break ;

		if (idx.compare("0") == 0) {
			showIndexes();
			std::cout << ">> ";
			continue ;
		}
		switch (atoi(idx.c_str())) {
			case 1: {
				constructorsTests();
				break ;
			}
		}
		std::cout << ">> ";
	}
	return 0;
}
