#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"

static void	constructorTests() {
	std::cout << "Create an int vector wich contains 5 elements and create a stack with this vector" << std::endl;
	ft::vector<int>	intVector(5, 67);
	ft::stack<int>	intStack(intVector);

	std::cout << "Is stack empty?: " << std::boolalpha << intStack.empty() << std::endl;
	std::cout << "Stack size: " << intStack.size() << std::endl;
	std::cout << std::endl;
}

static void	memberFunctionTests() {
	std::cout << "Create an float vector wich contains 5 elements and create a stack with it, the last element is 42.42" << std::endl << std::endl;
	ft::vector<float>	floatVector(4, 96.8);
	ft::stack<int>		emptyStack;

	floatVector.push_back(42.42);
	ft::stack<float>	floatStack(floatVector);

	std::cout << "Is stack empty?: " << std::boolalpha << floatStack.empty() << std::endl;
	std::cout << "Test with default constructor (empty stack): " << emptyStack.empty() << std::endl;

	std::cout << std::endl;
	std::cout << "Stack size: " << floatStack.size() << std::endl;
	std::cout << "Stack top element: " << floatStack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "Push 56.29 in the stack" << std::endl;
	floatStack.push(56.29);
	std::cout << "Stack size: " << floatStack.size() << std::endl;
	std::cout << "Stack top element: " << floatStack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "Remove the last element two times" << std::endl;
	floatStack.pop();
	floatStack.pop();
	std::cout << "Stack size: " << floatStack.size() << std::endl;
	std::cout << "Stack top element: " << floatStack.top() << std::endl;
	std::cout << std::endl;
}

static void	nonMemberFunctionTests() {
	std::cout << "Create two stacks that contains the same contents but a different size" << std::endl;
	ft::vector<char>	charVector1(5, 'a');
	ft::vector<char>	charVector2(6, 'a');
	ft::stack<char>		charStack1(charVector1);
	ft::stack<char>		charStack2(charVector2);

	std::cout << "charStack1's size: " << charStack1.size() << std::endl;
	std::cout << "charStack2's size: " << charStack2.size() << std::endl;

	std::cout << std::endl;
	std::cout << std::boolalpha;
	std::cout << "stack1 == stack2: " << (charStack1 == charStack2) << std::endl;
	std::cout << "stack1 != stack2: " << (charStack1 != charStack2) << std::endl;
	std::cout << "stack1 < stack2: " << (charStack1 < charStack2) << std::endl;
	std::cout << "stack1 <= stack2: " << (charStack1 <= charStack2) << std::endl;
	std::cout << "stack1 > stack2: " << (charStack1 > charStack2) << std::endl;
	std::cout << "stack1 >= stack2: " << (charStack1 >= charStack2) << std::endl;
	std::cout << std::endl;
}

static void	showTestList() {
	std::cout << "\033[33mList of category to test:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tConstructor" << std::endl;
	std::cout << " \'1\'\tMember functions" << std::endl;
	std::cout << " \'2\'\tNon member functions" << std::endl;
	std::cout << "\033[31m";
	std::cout << "\'exit\'\tMain menu" << std::endl;
	std::cout << "\033[33m";
	std::cout << "> ";
}

void	stackTests() {
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
				memberFunctionTests();
				break ;
			}
			case 2: {
				nonMemberFunctionTests();
				break ;
			}
			default:
				break ;
		}
		std::cout << "\033[0m";
		showTestList();
	}
}
