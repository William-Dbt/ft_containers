#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include "map.hpp"
#include "pair.hpp"

static void	constructorTests() {
	// Todo
	;
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
	std::cout << "Key of last element: " << it->first << std::endl;

	std::cout << std::endl;
	std::cout << "Print all elements thanks to begin() and end() function:" << std::endl;
	std::cout << "~ ";
	for (it = people.begin(); it != people.end(); it++)
		std::cout << it->first << ' ';

	std::cout << std::endl << std::endl;
	std::cout << "Try reverse_iterator:" << std::endl;
	ft::map<std::string, int>::reverse_iterator	revIt;

	// TODO - Check why infinite loop
	// revIt = people.rbegin();
	// std::cout << "Key of rbegin (last element): " << revIt->first << std::endl;
	revIt = people.rend();
	revIt--;
	std::cout << "Key of rend (first element): " << revIt->first << std::endl;
	std::cout << std::endl;
}

static void	capacityTests() {
	std::cout << "Create an empty map" << std::endl;
	ft::map<int, int>	time;

	std::cout << std::boolalpha;
	std::cout << "Is map empty? : " << time.empty() << std::endl;
	std::cout << "Size: " << time.size() << std::endl;
	std::cout << "Max_size: " << time.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << "Fill the map with two elements" << std::endl;
	time.insert(ft::pair<int, int>(12, 12));
	time.insert(ft::pair<int, int>(16, 48));
	std::cout << "Is map empty? : " << time.empty() << std::endl;
	std::cout << "Size: " << time.size() << std::endl;
	std::cout << "Max_size: " << time.max_size() << std::endl;
	std::cout << std::endl;
}

static void	accessTests() {
	std::cout << "Create a map of string and int" << std::endl;
	ft::map<std::string, int>	keys;

	keys.insert(ft::pair<std::string, int>("left", 4));
	keys.insert(ft::pair<std::string, int>("right", 6));
	keys.insert(ft::pair<std::string, int>("up", 8));
	keys.insert(ft::pair<std::string, int>("down", 2));
	std::cout << "Try to access elements with operator[]:" << std::endl;
	std::cout << "[left] = " << keys["left"] << std::endl;
	std::cout << "[right] = " << keys["right"] << std::endl;
	std::cout << "[up] = " << keys["up"] << std::endl;
	std::cout << "[down] = " << keys["down"] << std::endl;

	std::cout << std::endl;
	std::cout << "Try to change value of \"right\" to 999:" << std::endl;
	keys["right"] = 999;
	std::cout << "New \"right\" value: " << keys["right"] << std::endl;

	std::cout << std::endl;
	std::cout << "Try to add value that doesn't exist (space mapped on 101):" << std::endl;
	keys["space"] = 101;
	std::cout << "New \"space\" variable value: " << keys["space"] << std::endl;

	std::cout << std::endl;
	std::cout << "Try to find values with at() function:" << std::endl;
	try {
		std::cout << "- Value that doesn't exist, as \"escape\"" << std::endl;
		keys.at("escape");
		std::cerr << "Error: exception failed" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Out of range exception: " << e.what() << std::endl;
	}
	std::cout << "- Value \"right\": " << keys.at("right") << std::endl;
	std::cout << "- Value \"left\": " << keys.at("left") << std::endl;
	std::cout << "- Value \"up\": " << keys.at("up") << std::endl;
	std::cout << "- Value \"down\": " << keys.at("down") << std::endl;
	std::cout << "Right value isn't good, let's change it" << std::endl;
	keys.at("right") = 6;
	std::cout << "- Value \"right\": " << keys.at("right") << std::endl;
	std::cout << std::endl;
	
}

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << " \'1\'\tIterator" << std::endl;
	std::cout << " \'2\'\tCapacity" << std::endl;
	std::cout << " \'3\'\tAccess" << std::endl;
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
			case 2: {
				capacityTests();
				break ;
			}
			case 3: {
				accessTests();
				break ;
			}
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}