#include <iostream>
#include <cstdlib>
#include <string>
#include "vector.hpp"

static void	iteratorTests() {
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Let's fill a vector of 5 elements and print them with iterator:" << std::endl;
	ft::vector<int>				intVector(5);

	for (int i = 0; i < (int)intVector.size(); i++)
		intVector[i] = i;

	ft::vector<int>::iterator	it_begin = intVector.begin();
	ft::vector<int>::iterator	it_end = intVector.end();

	std::cout << "With operator++:";
	for (; it_begin != it_end; it_begin++)
		std::cout << ' ' << *it_begin;

	std::cout << std::endl;
	it_end = intVector.begin();
	--it_begin;
	std::cout << "With operator--:";
	for (; it_begin >= it_end; it_begin--)
		std::cout << ' ' << *it_begin;

	std::cout << std::endl << std::endl;
	std::cout << "Let's fill a vector of 5 elements and print them with const iterator:" << std::endl;
	ft::vector<int>				intConstVector(5);

	for (int i = 0; i < (int)intConstVector.size(); i++)
		intConstVector[i] = i;

	ft::vector<int>::const_iterator	itconst_begin = intConstVector.begin();
	ft::vector<int>::const_iterator	itconst_end = intConstVector.end();

	std::cout << "With operator++:";
	for (; itconst_begin != itconst_end; itconst_begin++)
		std::cout << ' ' << *itconst_begin;

	std::cout << std::endl;
	itconst_end = intConstVector.begin();
	--itconst_begin;
	std::cout << "With operator--:";
	for (; itconst_begin >= itconst_end; itconst_begin--)
		std::cout << ' ' << *itconst_begin;

	std::cout << std::endl << std::endl;
	std::cout << "Let's fill a vector of 5 elements and print them with reverse iterator:" << std::endl;
	ft::vector<int>				intReverseVector(5);

	for (int i = 0; i < (int)intReverseVector.size(); i++)
		intReverseVector[i] = i;

	ft::vector<int>::reverse_iterator	it_rev_begin = intReverseVector.rbegin();
	ft::vector<int>::reverse_iterator	it_rev_end = intReverseVector.rend();

	std::cout << "With operator++:";
	for (; it_rev_begin != it_rev_end; it_rev_begin++)
		std::cout << ' ' << *it_rev_begin;

	std::cout << std::endl;
	it_rev_end = intReverseVector.rbegin();
	--it_rev_begin;
	std::cout << "With operator--:";
	for (; it_rev_begin >= it_rev_end; it_rev_begin--)
		std::cout << ' ' << *it_rev_begin;

	std::cout << std::endl << std::endl;
	std::cout << "Let's fill a vector of 5 elements and print them with const reverse iterator:" << std::endl;
	ft::vector<int>				intConstReverseVector(5);

	for (int i = 0; i < (int)intConstReverseVector.size(); i++)
		intConstReverseVector[i] = i;

	ft::vector<int>::const_reverse_iterator	it_const_rev_begin = intConstReverseVector.rbegin();
	ft::vector<int>::const_reverse_iterator	it_const_rev_end = intConstReverseVector.rend();

	std::cout << "With operator++:";
	for (; it_const_rev_begin != it_const_rev_end; it_const_rev_begin++)
		std::cout << ' ' << *it_const_rev_begin;

	std::cout << std::endl;
	it_const_rev_end = intConstReverseVector.rbegin();
	--it_const_rev_begin;
	std::cout << "With operator--:";
	for (; it_const_rev_begin >= it_const_rev_end; it_const_rev_begin--)
		std::cout << ' ' << *it_const_rev_begin;

	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

static void	capacityTests() {
	int	i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Create a vector container which contains 5 content (18 here):" << std::endl;
	ft::vector<int>	intVector(5, 18);

	std::cout << "Vector size: " << intVector.size() << std::endl;
	std::cout << "The maximum size available is: " << intVector.max_size() << std::endl;
	std::cout << "Let's print the vector:" << std::endl;
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;
	
	std::cout << std::endl;
	intVector.resize(8);
	std::cout << "Size and capacity after resize of 8: " << intVector.size() << '|' << intVector.capacity() << std::endl << std::endl;

	std::cout << "Let's try to resize above capacity (like 15 and fill by 42):" << std::endl;
	intVector.resize(15, 42);
	std::cout << "New size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << "And that's the vector:" << std::endl;
	for (i = 0; i < (int)intVector.size(); i++)
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
	catch (std::length_error &e) {
		std::cerr << "Length error: " << e.what() << std::endl;
	}

	/*	Test about shrink_to_fit() function (C++11)
	std::cout << std::endl;
	std::cout << "Let's take the intVector created before (size " << intVector.size() << " and capacity " << intVector.capacity() << ')' << std::endl;
	std::cout << "The capacity is bigger than the size and we don't need them anymore! Let's shrink_to_fit" << std::endl;
	intVector.shrink_to_fit();
	std::cout << "The capacity is now: " << intVector.capacity() << " and the size: " << intVector.size() << std::endl;
	std::cout << "Let's print the vector to check if all content is here:" << std::endl;
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl; */

	std::cout << "----------------------------------------" << std::endl;
}

static void	accessTests() {
	int	i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Create a vector of 5 string elements:" << std::endl;
	ft::vector<std::string>	strVector(5);

	std::cout << "Size and capacity: " << strVector.size() << '|' << strVector.capacity() << std::endl << std::endl;
	std::cout << "Let's fill the 1st, 2nd and 3rd element with [] operator" << std::endl;
	strVector[0] = "Toto";
	strVector[1] = "Tutu";
	strVector[2] = "Titi";

	std::cout << "Now fill the last one with .at function" << std::endl;
	strVector.at(3) = "Tete";
	strVector.at(4) = "Tata";

	std::cout << "Print the vector:" << std::endl;
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << strVector[i] << std::endl;
	
	std::cout << std::endl;
	std::cout << "Is it possible to fill the 6th element?" << std::endl;
	try {
		strVector.at(5) = "Tyty";
		std::cerr << "error: exception .at function test" << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cerr << "Out of range exception: " << e.what() << std::endl;
	}
	std::cout << "Nope." << std::endl;

	std::cout << std::endl;
	std::cout << "Catch the first element of strVector with front() function: " << strVector.front() << std::endl;
	std::cout << "And now catch the last element: " << strVector.back() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's change values of strVector with a copy of his data:" << std::endl;
	std::string	*data = strVector.data();

	*data++ = "Hello!";
	*data++ = "My";
	data[0] = "name";
	data[1] = "is";
	data[2] = "Frankie.";
	std::cout << "Let's print the vector:" << std::endl;
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << strVector[i] << std::endl;

	std::cout << "----------------------------------------" << std::endl;
}

static void	modifiersTests() {
	int	i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Create a vector of size 5:" << std::endl;
	ft::vector<int>		intVector(5, 66);

	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "Assign the intVector by 2 contents of 15:" << std::endl;
	intVector.assign(2, 15);
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	ft::vector<int>	itVector(10, 42);

	std::cout << "Assign the intVector with iterators of itVectors that contains 10 elements of 42:" << std::endl;
	intVector.assign(itVector.begin(), itVector.end());
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;

	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's add some stuff to the vector:" << std::endl;
	for (i = 0; i < 10; i++)
		intVector.push_back(i);

	std::cout << "..." << std::endl;
	for (i = 5; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;
	
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	
	std::cout << std::endl;
	std::cout << "Maybe one more?" << std::endl;
	intVector.push_back(69);
	std::cout << "..." << std::endl;
	for (i = 15; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's remove the last element:" << std::endl;
	intVector.pop_back();
	for (i = 15; i < (int)intVector.size(); i++)
		std::cout << intVector[i] << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's remain the intVector:";
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;	
	std::cout << "Get an iterator at the 11th position. Value: ";
	ft::vector<int>::iterator	it = intVector.begin();

	for (i = 0; i < 10; i++)
		it++;

	std::cout << *it << std::endl;
	std::cout << "Set value \'-1\' before \'0\':" << std::endl;
	it = intVector.insert(it, -1);
	std::cout << "...";
	for (i = 5; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "Test two times with an empty vector and vector of size one:" << std::endl;
	ft::vector<std::string>				strVector;
	ft::vector<std::string>::iterator	strIt;

	strIt = strVector.begin();
	strIt = strVector.insert(strIt, "Toto");
	std::cout << "Value just added: " << *strIt << std::endl;
	std::cout << "strVector:";
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "Add the second one:" << std::endl;
	strIt = strVector.begin() + 1;
	strIt = strVector.insert(strIt, "Titi");
	std::cout << "Value just added: " << *strIt << std::endl;
	std::cout << "strVector:";
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl;
	strVector.insert(strIt, 5, "Tutu");
	std::cout << "----------------------------------------" << std::endl;
}

static void	allocatorTest() {
	ft::vector<int>	intVector;
	int				*allocator;
	int				i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Let's create a int vector with allocator of get_allocator()" << std::endl;
	allocator = intVector.get_allocator().allocate(5);
	for (i = 0; i < 5; i++)
		intVector.get_allocator().construct(&allocator[i], i);

	for (i = 0; i < 5; i++)
		std::cout << allocator[i] << std::endl;

	for (i = 0; i < 5; i++)
		intVector.get_allocator().destroy(&allocator[i]);

	intVector.get_allocator().deallocate(allocator, 5);
	std::cout << "----------------------------------------" << std::endl;
}

static void	showTestList() {
	std::cout << "List of tests:" << std::endl;
	std::cout << "0: Show list" << std::endl;
	std::cout << "1: Iterators tests" << std::endl;
	std::cout << "2: Capacity" << std::endl;
	std::cout << "3: Element access" << std::endl;
	std::cout << "4: Modifiers" << std::endl;
	std::cout << "5: Allocator" << std::endl;
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
				allocatorTest();
				break ;
			}
		}
		std::cout << "> ";
	}
}