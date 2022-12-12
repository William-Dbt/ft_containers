#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "vector.hpp"

static void	vectorTests() {
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Default constructor:" << std::endl;
	ft::vector<int>	intVector;

	std::cout << "intVector size & capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "Initialized size constructor:" << std::endl;
	ft::vector<std::string>	strVector(5);

	std::cout << "strVector size & capacity: " << strVector.size() << '|' << strVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Initialized size and value constructor (to 42.42):" << std::endl;
	ft::vector<float>	floatVector(5, 42.42);

	std::cout << "floatVector size & capacity: " << floatVector.size() << '|' << floatVector.capacity() << std::endl;
	for (int i = 0; i < (int)strVector.size(); i++)
		std::cout << i << ": " << floatVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Iterator first and end (of std::vector) initialized to 99 constructor:" << std::endl;
	std::vector<int>	stdVector(10, 99);
	ft::vector<int>		intItVector(stdVector.begin(), stdVector.end());

	std::cout << "intItVector size & capacity: " << intItVector.size() << '|' << intItVector.capacity() << std::endl;
	for (int i = 0; i < (int)intItVector.size(); i++)
		std::cout << i << ": " << intItVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Copy (from intItVector) constructor:" << std::endl;
	ft::vector<int>	intCopyVector(intItVector);

	std::cout << "intCopyVector size & capacity: " << intCopyVector.size() << '|' << intCopyVector.capacity() << std::endl;
	for (int i = 0; i < (int)intCopyVector.size(); i++)
		std::cout << i << ": " << intCopyVector[i] << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

static void	showContainerList() {
	std::cout << "List of containers:" << std::endl;
	std::cout << "0: Show list" << std::endl;
	std::cout << "1: Vector" << std::endl;
	std::cout << "exit: Main menu" << std::endl << std::endl;
}

void	constructorsTests() {
	std::string	idx;

	std::cout << std::endl;
	showContainerList();
	std::cout << "Which container do you want to test: ";
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
