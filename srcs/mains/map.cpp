#include <iostream>
#include <cstdlib>
#include "map.hpp"

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	// std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << "\033[31m";
	std::cout << "\'exit\'\tMain menu" << std::endl;
	std::cout << "\033[33m";
	std::cout << "> ";
}

void	mapTests() {
	std::string	idx;

	showTestList();
	while (std::getline(std::cin, idx)) {
		std::cout << std::endl;
		if (idx.compare("exit") == 0)
			break ;

		if (idx.size() == 0) {
			showTestList();
			continue ;
		}
		std::cout << "\033[97m";
		switch (atoi(idx.c_str())) {
			// case 0: {
			// 	constructorTests();
			// 	break ;
			// }
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}