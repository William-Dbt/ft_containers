#include <iostream>
#include <cstdlib>
#include <string>
#include "map.hpp"
#include <map>

static void	constructorTests() {
	// std::map<int, float>	mapTest;

	// mapTest.insert(ft::pair<int, float>(1, 2));
	// mapTest.insert(ft::pair<int, float>(2, 3));
	// mapTest.insert(ft::pair<int, float>(3, 4));

	// std::map<int, float>::iterator	it;
	
	// for (it = mapTest.begin(); it != mapTest.end(); it++)
	// 	std::cout << it->first << ' ' << it->second << std::endl;
}

static void	iteratorTests() {
	std::cout << "Create a map container of 7 contents" << std::endl;
	ft::map<std::string, int>			mapName;
	ft::map<std::string, int>::iterator	it;

	mapName.insert(ft::pair<std::string, int>("Jean", 42));
	mapName.insert(ft::pair<std::string, int>("Mich", 12));
	mapName.insert(ft::pair<std::string, int>("Paul", 56));
	mapName.insert(ft::pair<std::string, int>("Adri", 34));
	mapName.insert(ft::pair<std::string, int>("Abil", 99));
	mapName.insert(ft::pair<std::string, int>("Bill", 4));
	mapName.insert(ft::pair<std::string, int>("Celi", 2));
	it = mapName.begin();
	std::cout << "Value of begin: " << *it << std::endl;
	it = mapName.end();
	std::cout << "Value of end: " << *it << std::endl << std::endl;

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