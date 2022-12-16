#include <iostream>
#include <cstdlib>

void	vectorTests();

static void	showIndexes() {
	std::cout << "List of tests:" << std::endl;
	std::cout << "0: Show list" << std::endl;
	std::cout << "1: Vector Tests" << std::endl;
	std::cout << "exit: Exit program" << std::endl << std::endl;
}

int	main() {
	std::string	idx;

	showIndexes();
	std::cout << "Please enter the number of the test to execute: ";
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
				vectorTests();
				break ;
			}
		}
		std::cout << ">> ";
	}
	return 0;
}
