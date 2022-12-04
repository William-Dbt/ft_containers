#include <iostream>
#include <cstdlib>
#include "vector.hpp"

static void	capacityTests() {
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Create a vector container which contains 5 content (18 here):" << std::endl;
	ft::vector<int>	intVector(5, 18);

	std::cout << "Vector size: " << intVector.size() << std::endl;
	std::cout << "The maximum size available is: " << intVector.max_size() << std::endl;
	std::cout << "Let's print the vector:" << std::endl;
	for (int i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

static void	showTestList() {
	std::cout << "List of tests:" << std::endl;
	std::cout << "0: Show list" << std::endl;
	std::cout << "2: Capacity tests" << std::endl;
	std::cout << "exit: Main menu" << std::endl << std::endl;
}

void	vectorTests() {
	std::string	idx;

	std::cout << std::endl;
	showTestList();
	std::cout << "Which test do you want to see: ";
	while (std::getline(std::cin, idx)) {
		if (idx.compare("exit") == 0)
			break ;

		if (idx.compare("0") == 0) {
			showTestList();
			std::cout << "> ";
			continue ;
		}

		switch (atoi(idx.c_str())) {
			case 2: {
				capacityTests();
				break ;
			}
		}
		std::cout << "> ";
	}
}
