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
	
	std::cout << std::endl;
	intVector.resize(8);
	std::cout << "Size and capacity after resize of 8: " << intVector.size() << '|' << intVector.capacity() << std::endl << std::endl;

	std::cout << "Let's try to resize above capacity (like 15 and fill by 42):" << std::endl;
	intVector.resize(15, 42);
	std::cout << "New size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << "And that's the vector:" << std::endl;
	for (int i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Create an empty vector and check if it's empty:" << std::endl;
	ft::vector<char>	cVector;

	std::cout << "Is vector empty? " << std::boolalpha << cVector.empty() << std::endl;
	std::cout << std::endl << "Now let's try with previous vector: " << std::boolalpha << intVector.empty() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try to reserve some capacity:" << std::endl;
	std::cout << "The capacity of cVector is: " << cVector.capacity() << std::endl;
	std::cout << "Let's reserve 10 spaces of memory.";
	cVector.reserve(10);
	std::cout << "The cVector capacity is now: " << cVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Can we reserve more than max_size? (should throw length_error)" << std::endl;
	try {
		cVector.reserve(cVector.max_size() + 1);
		std::cerr << "error: exception on reserve more than max_size" << std::endl;
	}
	catch (std::length_error &le) {
		std::cerr << "Length error: " << le.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Let's take the intVector created before (size " << intVector.size() << " and capacity " << intVector.capacity() << ')' << std::endl;
	std::cout << "The capacity is bigger than the size and we don't need them anymore! Let's shrink_to_fit" << std::endl;
	intVector.shrink_to_fit();
	std::cout << "The capacity is now: " << intVector.capacity() << " and the size: " << intVector.size() << std::endl;
	std::cout << "Let's print the vector to check if all content is here:" << std::endl;
	for (int i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

static void	showTestList() {
	std::cout << "List of tests:" << std::endl;
	std::cout << "0: Show list" << std::endl;
	std::cout << "2: Capacity tests" << std::endl;
	std::cout << "3: Element access" << std::endl;
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
