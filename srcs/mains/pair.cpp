#include <iostream>
#include <string>
#include "pair.hpp"

void	pairTests() {
	{
		ft::pair<std::string, int>	pair;

		std::cout << "Let's fill a pair of string and int" << std::endl;
		pair = ft::make_pair("Toto", 5);
		std::cout << pair.first << std::endl;
		std::cout << pair.second << std::endl;

		std::cout << std::endl;
		ft::pair<std::string, int>	pair2;
		std::cout << "Let's fill a pair2 of same string and different int" << std::endl;
		pair2 = ft::make_pair("Toto", 10);
		std::cout << pair2.first << std::endl;
		std::cout << pair2.second << std::endl;

		std::cout << std::endl;
		std::cout << std::boolalpha;
		std::cout << "operator==: " << (pair == pair2) << std::endl;
		std::cout << "operator!=: " << (pair != pair2) << std::endl;
		std::cout << "operator<: " << (pair < pair2) << std::endl;
		std::cout << "operator<=: " << (pair <= pair2) << std::endl;
		std::cout << "operator>: " << (pair > pair2) << std::endl;
		std::cout << "operator>=: " << (pair >= pair2) << std::endl;

		std::cout << std::endl;
		std::cout << "Operator by assigment (Tutu and 54):" << std::endl;
		ft::pair<std::string, int>	assignPair("Tutu", 54);

		std::cout << assignPair.first << std::endl;
		std::cout << assignPair.second << std::endl;

		std::cout << std::endl;
		std::cout << "Operator by copy (from pair):" << std::endl;
		ft::pair<std::string, int>	copyPair(pair);

		std::cout << copyPair.first << std::endl;
		std::cout << copyPair.second << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\033[36m";
		std::pair<std::string, int>	pair;

		std::cout << "Let's fill a pair of string and int" << std::endl;
		pair = std::make_pair("Toto", 5);
		std::cout << pair.first << std::endl;
		std::cout << pair.second << std::endl;

		std::cout << std::endl;
		std::pair<std::string, int>	pair2;
		std::cout << "Let's fill a pair2 of same string and different int" << std::endl;
		pair2 = std::make_pair("Toto", 10);
		std::cout << pair2.first << std::endl;
		std::cout << pair2.second << std::endl;

		std::cout << std::endl;
		std::cout << std::boolalpha;
		std::cout << "operator==: " << (pair == pair2) << std::endl;
		std::cout << "operator!=: " << (pair != pair2) << std::endl;
		std::cout << "operator<: " << (pair < pair2) << std::endl;
		std::cout << "operator<=: " << (pair <= pair2) << std::endl;
		std::cout << "operator>: " << (pair > pair2) << std::endl;
		std::cout << "operator>=: " << (pair >= pair2) << std::endl;

		std::cout << std::endl;
		std::cout << "Operator by assigment (Tutu and 54):" << std::endl;
		std::pair<std::string, int>	assignPair("Tutu", 54);

		std::cout << assignPair.first << std::endl;
		std::cout << assignPair.second << std::endl;

		std::cout << std::endl;
		std::cout << "Operator by copy (from pair):" << std::endl;
		std::pair<std::string, int>	copyPair(pair);

		std::cout << copyPair.first << std::endl;
		std::cout << copyPair.second << std::endl;
		std::cout << "\033[0m";
		std::cout << std::endl;
	}
}