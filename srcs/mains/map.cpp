#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include "map.hpp"
#include "pair.hpp"

static void	constructorTests() {
	std::cout << "Try to create an empty container" << std::endl;
	ft::map<char, int>				map;
	ft::map<char, int>::iterator	it;

	std::cout << "map.size(): " << map.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Fill some values in the map and print them" << std::endl;
	map.insert(ft::pair<char, int>('a', 1));
	map.insert(ft::pair<char, int>('b', 2));
	map.insert(ft::pair<char, int>('c', 3));
	map.insert(ft::pair<char, int>('d', 4));
	for (it = map.begin(); it != map.end(); it++)
		std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
	
	std::cout << "Map size: " << map.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Create a container by copy of map and print content" << std::endl;
	ft::map<char, int>	copyMap(map);

	for (it = copyMap.begin(); it != copyMap.end(); it++)
		std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
	
	std::cout << "copyMap size: " << copyMap.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Try the operator with iterators" << std::endl;
	ft::map<char, int>	iteratorMap(map.begin(), map.end());

	for (it = iteratorMap.begin(); it != iteratorMap.end(); it++)
		std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;

	std::cout << "iteratorMap size: " << iteratorMap.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Create an empty container and test operator= on it" << std::endl;
	ft::map<char, int>	operatorMap;

	operatorMap = map;
	for (it = operatorMap.begin(); it != operatorMap.end(); it++)
		std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;

	std::cout << "operatorMap size: " << operatorMap.size() << std::endl;
	std::cout << std::endl;
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

	revIt = people.rbegin();
	std::cout << "Key of rbegin (last element): " << revIt->first << std::endl;
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
	std::cout << "Try to add value that doesn't exist (\"space\" mapped on 101):" << std::endl;
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

	std::cout << std::endl;
	std::cout << "Right value isn't good, let's change it" << std::endl;
	keys.at("right") = 6;
	std::cout << "- Value \"right\": " << keys.at("right") << std::endl;
	std::cout << std::endl;
	
}

static void	modifiersTests() {
	std::cout << "Create an empty map" << std::endl;
	ft::map<std::string, int>							addressNeighbors;
	ft::pair<ft::map<std::string, int>::iterator, bool>	buffer;
	ft::map<std::string, int>::iterator					it;

	std::cout << "Insert two elements ([Paul, 14] & [Jean, 16]) " << std::endl;
	addressNeighbors.insert(ft::pair<std::string, int>("Paul", 14));
	addressNeighbors.insert(ft::pair<std::string, int>("Jean", 16));

	std::cout << std::endl << "Insert a second time Jean and check the return pair value of insert() function:" << std::endl;
	buffer = addressNeighbors.insert(ft::pair<std::string, int>("Jean", 16));
	if (buffer.second == false) {
		std::cout << "Pair.second value is false, no new element created." << std::endl;
		std::cout << "Element \"Jean\" already exist: [Jean, " << addressNeighbors["Jean"] << ']' << std::endl;
	}

	std::cout << std::endl;
	std::cout << "New map size: " << addressNeighbors.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Add new neighbor Ary, the first one of the street" << std::endl;
	it = addressNeighbors.insert(addressNeighbors.begin(), ft::pair<std::string, int>("Ary", 1));
	std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Now show the other neighbors (with the help of the returned iterator of Ary's insert (iterate to end())): " << std::endl;
	it++;
	for (; it != addressNeighbors.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Fill another map container with the first and end iterator of neighbors map:" << std::endl;
	ft::map<std::string, int>	copyAddress;

	copyAddress.insert(addressNeighbors.begin(), addressNeighbors.end());
	for (it = copyAddress.begin(); it != copyAddress.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Try to erase the first element of addressNeighbors (Ary) by calling erase(iterator)" << std::endl;
	addressNeighbors.erase(addressNeighbors.begin());
	for (it = addressNeighbors.begin(); it != addressNeighbors.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Try to remove the key \"Paul\":" << std::endl;
	addressNeighbors.erase("Paul");
	it = addressNeighbors.begin();
	for (it = addressNeighbors.begin(); it != addressNeighbors.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Remain of the copy of address:" << std::endl;
	for (it = copyAddress.begin(); it != copyAddress.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;
	
	std::cout << std::endl;
	std::cout << "Try to remove all the tree by .begin() and .end() iterator functions" << std::endl;
	copyAddress.erase(copyAddress.begin(), copyAddress.end());

	std::cout << "And try to print the map:" << std::endl;
	for (it = copyAddress.begin(); it != copyAddress.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Also the size of map: " << copyAddress.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Now addressNeighbors have one element and copyAddress zero." << std::endl;
	std::cout << "addressNeighbors.size(): " << addressNeighbors.size() << std::endl;
	std::cout << "copyAddress.size(): " << copyAddress.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Try to swap addressNeighbors with copyAddress and print contents" << std::endl;
	addressNeighbors.swap(copyAddress);
	std::cout << "addressNeighbors:" << std::endl;
	for (it = addressNeighbors.begin(); it != addressNeighbors.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "addressNeighbors.size(): " << addressNeighbors.size() << std::endl << std::endl;
	std::cout << "----------" << std::endl << std::endl;
	std::cout << "copyAddress:" << std::endl;
	for (it = copyAddress.begin(); it != copyAddress.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << "copyAddress.size(): " << copyAddress.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Try to clear copyAddress and try to print values with iterators (which is normally empty)" << std::endl;
	copyAddress.clear();
	for (it = copyAddress.begin(); it != copyAddress.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "copyAddress.size(): " << copyAddress.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Add two elements in addressNeighbors (Kylian and Boulito)" << std::endl;
	addressNeighbors["Kylian"] = 99;
	addressNeighbors["Boulito"] = 101;
	for (it = addressNeighbors.begin(); it != addressNeighbors.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << "addressNeighbors.size(): " << addressNeighbors.size() << std::endl;
	std::cout << std::endl;
}

static void	observersTest() {
	std::cout << "Create a map of two contents" << std::endl;
	ft::map<int, int>					map;

	map[3] = 3;
	map[5] = 5;
	std::cout << "Get the key value of the first and begin iterator" << std::endl;
	ft::map<int, int>::iterator			firstIt = map.begin();
	ft::map<int, int>::reverse_iterator	lastIt = map.rbegin();
	int	firstKey = firstIt->first;
	int	lastKey = lastIt->first;

	std::cout << "first: " << firstKey << " last: " << lastKey << std::endl;

	std::cout << std::endl;
	std::cout << "Now get the key_compare function to compare first and last key" << std::endl;
	ft::map<int, int>::key_compare	comp = map.key_comp();

	if (comp(firstKey, lastKey) == true)
		std::cout << "first is inferior than last" << std::endl;

	std::cout << std::endl;
	std::cout << "Now check the reverse" << std::endl;
	if (comp(lastKey, firstKey) == false)
		std::cout << "last is superior than first" << std::endl;

	std::cout << std::endl;
	std::cout << "Get the two pair of iterator on begin and end" << std::endl;
	ft::pair<int, int>	first = *(map.begin());
	ft::pair<int, int>	last = *(map.rbegin());

	std::cout << "first: " << first.first << " last: " << last.second << std::endl;

	std::cout << std::endl;
	std::cout << "Use value_comp() function (that returns true or false) to check if first is inferior than last" << std::endl;
	if (map.value_comp()(first, last) == true)
		std::cout << "first is inferior than last" << std::endl;

	std::cout << std::endl;
	std::cout << "Now check the reverse" << std::endl;
	if (map.value_comp()(last, first) == false)
		std::cout << "last is superior than first" << std::endl;

	std::cout << std::endl;
}

static void	operationsTests() {
	std::cout << "Create a map with a lot of int and print them" << std::endl;
	std::map<int, int>			intMap;
	std::map<int, int>::iterator	it;

	intMap[0] = 0;
	intMap[1] = 1;
	intMap[2] = 2;
	intMap[3] = 3;
	intMap[4] = 4;
	intMap[5] = 5;
	intMap[6] = 6;
	intMap[7] = 7;
	intMap[8] = 8;
	intMap[9] = 9;
	intMap[10] = 10;
	for (it = intMap.begin(); it != intMap.end(); it++)
		std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Get iterator of 5 with find() function" << std::endl;
	it = intMap.find(5);
	std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Try with an unknow key (should return the end() iterator, if we decrement this one, we get the last element)" << std::endl;
	it = intMap.find(76);
	it--;
	std::cout << "Name: " << it->first << ", number: " << it->second << std::endl;

	std::cout << std::endl;
	std::cout << "Count element in map with count() function (return 1 or 0 because we don't duplicate keys)" << std::endl;
	std::cout << "Is 3 in the map?: " << intMap.count(3) << std::endl;
	std::cout << "Is 42 in the map?: " << intMap.count(42) << std::endl;
	std::cout << "The count function can returns greater number but our tree doesn't allow multiple keys." << std::endl;

	std::cout << std::endl;
	std::cout << "Get two iterators from 2 to 7 with lower_bound() and upper_bound() functions and print the tab" << std::endl;
	std::map<int, int>::iterator	itLow, itUp;

	itLow = intMap.lower_bound(2);
	itUp = intMap.upper_bound(7);
	while (itLow != itUp)
		std::cout << (*itLow++).first << ' ';

	std::cout << std::endl;
	std::cout << "Check for equal_range() function at the key value 8" << std::endl;
	std::pair< std::map<int, int>::iterator, std::map<int, int>::iterator >	itPair;

	itPair = intMap.equal_range(8);

	std::cout << std::endl;
	std::cout << "first value is: " << itPair.first->first << std::endl;
	std::cout << "second value is: " << itPair.second->first << std::endl;
	std::cout << std::endl;
}

static void	allocatorTest() {
	int psize;
	ft::map<char,int>			mymap;
	ft::pair<const char, int>	*p;

	p = mymap.get_allocator().allocate(5);

	psize = sizeof(ft::map<char, int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes." << std::endl;
	mymap.get_allocator().deallocate(p, 5);
	std::cout << std::endl;
}

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << " \'1\'\tIterator" << std::endl;
	std::cout << " \'2\'\tCapacity" << std::endl;
	std::cout << " \'3\'\tAccess" << std::endl;
	std::cout << " \'4\'\tModifiers" << std::endl;
	std::cout << " \'5\'\tObservers" << std::endl;
	std::cout << " \'6\'\tOperations" << std::endl;
	std::cout << " \'7\'\tAllocator" << std::endl;
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
			case 4: {
				modifiersTests();
				break ;
			}
			case 5: {
				observersTest();
				break ;
			}
			case 6: {
				operationsTests();
				break ;
			}
			case 7: {
				allocatorTest();
				break ;
			}
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}