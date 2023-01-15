#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include "map.hpp"
#include "pair.hpp"

static void	constructorTests() {
	ft::map<int, float>	mapTest;

	mapTest.insert(ft::pair<int, float>(54, 2));
	mapTest.insert(ft::pair<int, float>(3, 2));
	mapTest.insert(ft::pair<int, float>(-2, 2));
	mapTest.insert(ft::pair<int, float>(-56, 2));
	mapTest.insert(ft::pair<int, float>(53, 2));
	mapTest.insert(ft::pair<int, float>(13, 2));

	ft::map<int, float>::iterator	it;

	for (it = mapTest.begin(); it != mapTest.end(); it++)
		std::cout << it->first << std::endl;

	std::cout << std::endl;
	it = mapTest.end();
	it--;
	for (; it != mapTest.begin(); it--)
		std::cout << it->first << std::endl;
}

static void	iteratorTests() {
	std::cout << "Create a map container of 7 contents" << std::endl;
	ft::map<std::string, int>			people;
	ft::map<std::string, int>::iterator	it;

	people.insert(ft::pair<std::string, int>("Emeline", 42));
	people.insert(ft::pair<std::string, int>("Franck", 12));
	people.insert(ft::pair<std::string, int>("Greg", 56));
	people.insert(ft::pair<std::string, int>("Dylan", 34));
	people.insert(ft::pair<std::string, int>("Abil", 99));
	people.insert(ft::pair<std::string, int>("Bill", 4));
	people.insert(ft::pair<std::string, int>("Celi", 2));
	it = people.begin();
	std::cout << "Key of first element: " << it->first << std::endl;
	it = people.end();
	it--;
	std::cout << "Key of last element: " << it->first << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Print all elements thanks to begin() and end() function:" << std::endl;
	std::cout << "~ ";
	for (it = people.begin(); it != people.end(); it++)
		std::cout << it->first << ' ';

	std::cout << std::endl;
	std::cout << std::endl;
}

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << " \'1\'\tIterator" << std::endl;
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
			case 0: {
				constructorTests();
				break ;
			}
			case 1: {
				iteratorTests();
				break ;
			}
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}