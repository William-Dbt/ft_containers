#include <iostream>
#include "vector.hpp"

static void	vectorTests() {
	std::cout << "Vector tests" << std::endl;
}

static void	showContainerList() {
	std::cout << "List of containers:" << std::endl;
	std::cout << "1: Vector" << std::endl << std::endl;
}

void	constructorsTests() {
	std::string	idx;

	std::cout << "Which container do you want to test (0 to show the list, \"exit\" to Main menu): ";
	while (std::getline(std::cin, idx)) {
		if (idx.compare("exit") == 0)
			break ;

		if (idx.compare("0") == 0) {
			showContainerList();
			std::cout << "> ";
			continue ;
		}

		switch (atoi(idx.c_str())) {
			case 1: {
				vectorTests();
				break ;
			}
		}
		std::cout << "> ";
	}
}
