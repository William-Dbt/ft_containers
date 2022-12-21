#include <iostream>
#include <cstdlib>
#include <string>
#include "vector.hpp"

static void	constructorTests() {
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
	for (int i = 0; i < (int)floatVector.size(); i++)
		std::cout << i << ": " << floatVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Fill with iterator and initialize to 99 constructor:" << std::endl;
	ft::vector<int>	stdVector(10, 99);
	ft::vector<int>	intItVector(stdVector.begin(), stdVector.end());

	std::cout << "intItVector size & capacity: " << intItVector.size() << '|' << intItVector.capacity() << std::endl;
	for (int i = 0; i < (int)intItVector.size(); i++)
		std::cout << i << ": " << intItVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Copy (from intItVector) constructor:" << std::endl;
	ft::vector<int>	intCopyVector(intItVector);

	std::cout << "intCopyVector size & capacity: " << intCopyVector.size() << '|' << intCopyVector.capacity() << std::endl;
	for (int i = 0; i < (int)intCopyVector.size(); i++)
		std::cout << i << ": " << intCopyVector[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Is operator= works? Let's copy the floatVector:" << std::endl;
	ft::vector<float>	cpFloatVector(5, 52.52);

	cpFloatVector = floatVector;
	for (int i = 0; i < (int)cpFloatVector.size(); i++)
		std::cout << i << ": " << cpFloatVector[i] << std::endl;

	std::cout << std::endl;
}

static void	iteratorTests() {
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
	std::cout << "Print two by two with iterator + n:";
	while (it_end < intVector.end()) {
		std::cout << ' ' << *it_end;
		it_end = it_end + 2;
	}
	std::cout << std::endl;
	std::cout << "And print the reverse with it - n:";
	it_end -= 2;
	while (it_end >= intVector.begin()) {
		std::cout << ' ' << *it_end;
		it_end = it_end - 2;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Let's fill a vector of 5 elements and print them with reverse iterator" << std::endl << std::endl;
	ft::vector<int>	intRevVector(5);

	for (int i = 0; i < (int)intRevVector.size(); i++)
		intRevVector[i] = i;

	ft::vector<int>::reverse_iterator	rev_it;

	std::cout << "Let's print the vector with operator++:";
	for (rev_it = intRevVector.rbegin(); rev_it != intRevVector.rend(); rev_it++)
		std::cout << ' ' << *rev_it;

	std::cout << std::endl;
	std::cout << "And operator--:";
	for (rev_it = intRevVector.rend() - 1; rev_it >= intRevVector.rbegin(); rev_it--)
		std::cout << ' ' << *rev_it;

	std::cout << std::endl << std::endl;
	std::cout << "Reverse Iterator is now after the (4) value," << std::endl;
	std::cout << "Let's call operator+(n) to get the last and the third value: ";
	std::cout << *(rev_it + 1) << ' ' << *(rev_it + 3) << std::endl;
	std::cout << "operator-(n) with iterator rend(): ";
	std::cout << *(intRevVector.rend() - 1) << ' ' << *(intRevVector.rend() - 3) << std::endl;

	std::cout << std::endl;
	rev_it = intRevVector.rend() - 1;
	std::cout << "Let's use += and -= operator by 2 to show the content of the vectors" << std::endl;
	std::cout << "operator-= starting from it.rend(): ";
	std::cout << *rev_it << ' ';
	rev_it -= 2;
	std::cout << *rev_it << ' ';
	rev_it -= 2;
	std::cout << *rev_it;
	std::cout << std::endl;

	std::cout << "And now with operator+=: ";
	std::cout << *rev_it << ' ';
	rev_it += 2;
	std::cout << *rev_it << ' ';
	rev_it += 2;
	std::cout << *rev_it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Let's check relational operators:" << std::endl;
	ft::vector<int>::reverse_iterator	revItA = intRevVector.rbegin();
	ft::vector<int>::reverse_iterator	revItB = intRevVector.rbegin();

	std::cout << std::boolalpha;
	std::cout << "operator==: " << (revItA == revItB) << std::endl;
	std::cout << "operator!=: " << (revItA != revItB) << std::endl;
	std::cout << "operator<: " << (revItA < revItB) << std::endl;
	std::cout << "operator<=: " << (revItA <= revItB) << std::endl;
	std::cout << "operator>: " << (revItA > revItB) << std::endl;
	std::cout << "operator>=: " << (revItA >= revItB) << std::endl;

	std::cout << std::endl;
	std::cout << "Increment revItB and show result:" << std::endl;
	revItB++;
	std::cout << "operator==: " << (revItA == revItB) << std::endl;
	std::cout << "operator!=: " << (revItA != revItB) << std::endl;
	std::cout << "operator<: " << (revItA < revItB) << std::endl;
	std::cout << "operator<=: " << (revItA <= revItB) << std::endl;
	std::cout << "operator>: " << (revItA > revItB) << std::endl;
	std::cout << "operator>=: " << (revItA >= revItB) << std::endl;

	std::cout << std::endl;
	std::cout << "intVector:";
	for (size_t i = 0; i < intRevVector.size(); i++)
		std::cout << ' ' << intRevVector[i];

	std::cout << std::endl;
	std::cout << "operator+(n, it), with n = 2 and it = rbegin(): ";
	revItA = 2 + intRevVector.rbegin();
	std::cout << *revItA << std::endl;

	std::cout << std::endl;
	revItA = intRevVector.rbegin();
	revItB = intRevVector.rend();
	std::cout << "My vector has: " << (revItB - revItA) << " elements. (Thanks to operator-(it))" << std::endl;
	std::cout << std::endl;
}

static void	capacityTests() {
	int	i;

	std::cout << "Create a vector container which contains 5 content (18 here):" << std::endl;
	ft::vector<int>	intVector(5, 18);

	std::cout << "Vector size: " << intVector.size() << std::endl;
	std::cout << "The maximum size available is: " << intVector.max_size() << std::endl;
	std::cout << "Let's print the vector:";
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];
	
	std::cout << std::endl << std::endl;
	intVector.resize(8);
	std::cout << "Size and capacity after resize of 8: " << intVector.size() << '|' << intVector.capacity() << std::endl << std::endl;

	std::cout << "Let's try to resize above capacity (like 15 and fill by 42):" << std::endl;
	intVector.resize(15, 42);
	std::cout << "New size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << "And that's the vector:";
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "Create an empty vector and check if it's empty:" << std::endl;
	ft::vector<char>	cVector;

	std::cout << "Is vector empty? " << std::boolalpha << cVector.empty() << std::endl;
	std::cout << std::endl << "Now let's try with previous vector: " << std::boolalpha << intVector.empty() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's try to reserve some capacity:" << std::endl;
	std::cout << "The capacity of cVector is: " << cVector.capacity() << std::endl;
	std::cout << "Let's reserve 10 spaces of memory." << std::endl;
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

	std::cout << std::endl;
}

static void	accessTests() {
	int	i;

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

	std::cout << std::endl;
}

static void	modifiersTests() {
	int	i;

	std::cout << "Create a vector of size 5:";
	ft::vector<int>		intVector(5, 66);

	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "Assign the intVector by 2 contents of 15:";
	intVector.assign(2, 15);
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	ft::vector<int>	itVector(10, 42);

	std::cout << "Assign the intVector with iterators of itVectors that contains 10 elements of 42:" << std::endl;
	std::cout << "intVector:";
	intVector.assign(itVector.begin(), itVector.end());
	for (i = 0; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's add some stuff to the vector:" << std::endl;
	for (i = 0; i < 10; i++)
		intVector.push_back(i);

	std::cout << "...";
	for (i = 5; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;
	
	std::cout << std::endl;
	std::cout << "Maybe one more?" << std::endl;
	intVector.push_back(42);
	std::cout << "...";
	for (i = 15; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
	std::cout << "Vector size and capacity: " << intVector.size() << '|' << intVector.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Let's remove the last element:";
	intVector.pop_back();
	for (i = 15; i < (int)intVector.size(); i++)
		std::cout << ' ' << intVector[i];

	std::cout << std::endl;
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

	std::cout << std::endl << std::endl;
	std::cout << "Let's add 5 \"Tutu\" in the vector at last added position:";
	strVector.insert(strIt, 5, "Tutu");
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl << std::endl;
	ft::vector<std::string>				namesVector(3);
	ft::vector<std::string>::iterator	ret;

	namesVector[0] = "Jean";
	namesVector[1] = "Michelle";
	namesVector[2] = "Paul";
	std::cout << "Now add three more elements at the first position:";
	strVector.insert(strVector.begin(), namesVector.begin(), namesVector.end());
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "Let's erase \"Toto\" from the list:";
	strIt = strVector.begin() + 3;
	ret = strVector.erase(strIt);
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "ret: " << *ret << " (value before: " << *(ret - 1) << ')' << std::endl;
	std::cout << "Now erase all \"Tutu\" from the list:";
	ret = strVector.erase(strVector.begin() + 3, strVector.end() - 1);
	for (i = 0; i < (int)strVector.size(); i++)
		std::cout << ' ' << strVector[i];

	std::cout << std::endl << std::endl;
	std::cout << "ret: " << *ret << std::endl;

	std::cout << "Create two vectors and swap their contents:" << std::endl;
	ft::vector<float>	vectorA(5, 42.42);
	ft::vector<float>	vectorB(2, 84.84);

	std::cout << "Vector A:";
	for (i = 0; i < (int)vectorA.size(); i++)
		std::cout << ' ' << vectorA[i];

	std::cout << std::endl;
	std::cout << "Vector B:";
	for (i = 0; i < (int)vectorB.size(); i++)
		std::cout << ' ' << vectorB[i];

	std::cout << std::endl << std::endl;
	std::cout << "Calling swap function" << std::endl << std::endl;
	vectorA.swap(vectorB);
	std::cout << "Vector A:";
	for (i = 0; i < (int)vectorA.size(); i++)
		std::cout << ' ' << vectorA[i];

	std::cout << std::endl;
	std::cout << "Vector B:";
	for (i = 0; i < (int)vectorB.size(); i++)
		std::cout << ' ' << vectorB[i];

	int	oldSize = vectorB.size();
	std::cout << std::endl << std::endl;
	std::cout << "Let's clear both A and B and check how std::allocator works:" << std::endl;
	vectorA.clear();
	vectorB.clear();
	std::cout << "vectorA.size(): " << vectorA.size() << std::endl;
	std::cout << "vectorB.size(): " << vectorB.size() << std::endl;
	std::cout << "vectorA.capacity(): " << vectorA.capacity() << std::endl;
	std::cout << "vectorB.capacity(): " << vectorB.capacity() << std::endl;
	std::cout << "The capacity don't changed because we just want to erase the datas of the vector." << std::endl;
	std::cout << "Now if we print for example the vector B, the values are still here because it's a float but," << std::endl;
	std::cout << "if it were an object, the object would have been deleted (by allocator.destroy())" << std::endl;

	std::cout << std::endl;
	std::cout << "vectorB:";
	for (i = 0; i < oldSize; i++)
		std::cout << ' ' << vectorB[i];

	std::cout << std::endl << std::endl;
	std::cout << "We still can read in the memory because the capacity doesn't change." << std::endl;
	std::cout << std::endl;
}

static void	allocatorTests() {
	ft::vector<int>	intVector;
	int				*allocator;
	int				i;

	std::cout << "Let's create a int vector with allocator of get_allocator()" << std::endl;
	allocator = intVector.get_allocator().allocate(5);
	for (i = 0; i < 5; i++)
		intVector.get_allocator().construct(&allocator[i], i);

	for (i = 0; i < 5; i++)
		std::cout << allocator[i] << std::endl;

	for (i = 0; i < 5; i++)
		intVector.get_allocator().destroy(&allocator[i]);

	intVector.get_allocator().deallocate(allocator, 5);
	std::cout << std::endl;
}

static void	nonMemberFunctionsTests() {
	int	i;

	std::cout << "Create two vectors A and B:" << std::endl;
	ft::vector<int>	vectorA(5, 100);
	ft::vector<int>	vectorB(5, 100);

	std::cout << "VectorA:";
	for (i = 0; i < (int)vectorA.size(); i++)
		std::cout << ' ' << vectorA[i];

	std::cout << std::endl;
	std::cout << "VectorB:";
	for (i = 0; i < (int)vectorB.size(); i++)
		std::cout << ' ' << vectorB[i];

	std::cout << std::endl << std::endl;
	std::cout << "Is their equal? : " << std::boolalpha << (vectorA == vectorB) << std::endl;
	std::cout << "Let's add an element to vector A:";
	vectorA.push_back(42);
	for (i = 0; i < (int)vectorA.size(); i++)
		std::cout << ' ' << vectorA[i];

	std::cout << std::endl;
	std::cout << "Is still equal? : " << std::boolalpha << (vectorB == vectorA) << std::endl;

	std::cout << std::endl;
	std::cout << "Let's check more compare operators:" << std::endl;
	std::cout << "vectorA != vectorB: " << std::boolalpha << (vectorA != vectorB) << std::endl;
	std::cout << std::endl;
	std::cout << "vectorA < vectorB: " << std::boolalpha << (vectorA < vectorB) << std::endl;
	std::cout << "vectorB < vectorA: " << std::boolalpha << (vectorB < vectorA) << std::endl;
	std::cout << std::endl;
	std::cout << "vectorA <= vectorB: " << std::boolalpha << (vectorA <= vectorB) << std::endl;
	std::cout << "vectorB <= vectorA: " << std::boolalpha << (vectorB <= vectorA) << std::endl;
	std::cout << std::endl;
	std::cout << "vectorA > vectorB: " << std::boolalpha << (vectorA > vectorB) << std::endl;
	std::cout << "vectorB > vectorA: " << std::boolalpha << (vectorB > vectorA) << std::endl;
	std::cout << std::endl;
	std::cout << "vectorA >= vectorB: " << std::boolalpha << (vectorA >= vectorB) << std::endl;
	std::cout << "vectorB >= vectorA: " << std::boolalpha << (vectorB >= vectorA) << std::endl;

	std::cout << std::endl;
	std::cout << "Create third vector to test >= and <= equal operator:";
	ft::vector<int>	vectorC(vectorB);

	for (i = 0; i < (int)vectorC.size(); i++)
		std::cout << ' ' << vectorC[i];

	std::cout << std::endl;
	std::cout << "VectorA:";
	for (i = 0; i < (int)vectorA.size(); i++)
		std::cout << ' ' << vectorA[i];

	std::cout << std::endl;
	std::cout << "VectorB:";
	for (i = 0; i < (int)vectorB.size(); i++)
		std::cout << ' ' << vectorB[i];

	std::cout << std::endl << std::endl;
	std::cout << "vectorC >= vectorA: " << std::boolalpha << (vectorC >= vectorA) << std::endl;
	std::cout << "vectorC >= vectorB: " << std::boolalpha << (vectorC >= vectorB) << std::endl;
	std::cout << std::endl;
	std::cout << "vectorC <= vectorA: " << std::boolalpha << (vectorC <= vectorA) << std::endl;
	std::cout << "vectorC <= vectorB: " << std::boolalpha << (vectorC <= vectorB) << std::endl;
	std::cout << std::endl;
}

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << " \'1\'\tIterators" << std::endl;
	std::cout << " \'2\'\tCapacity" << std::endl;
	std::cout << " \'3\'\tElement access" << std::endl;
	std::cout << " \'4\'\tModifiers" << std::endl;
	std::cout << " \'5\'\tAllocator" << std::endl;
	std::cout << " \'6\'\tNon member functions" << std::endl;
	std::cout << "\033[31m";
	std::cout << "\'exit\'\tMain menu" << std::endl;
	std::cout << "\033[33m";
	std::cout << "> ";
}

void	vectorTests() {
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
				allocatorTests();
				break ;
			}
			case 6: {
				nonMemberFunctionsTests();
				break ;
			}
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}
