#include <iostream>
#include "pair.hpp"
#include "binary_search_tree.hpp"

void	BSTTests() {
	ft::BSTree< ft::pair<int, float> >	tree;

	std::cout << "Create an empty binary tree and try to print values: ";
	tree.printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Now fill with values 10, 1, 99, 3256, 4 paired with 42.42 and print keys in order: ";
	tree.addLeaf(ft::make_pair(5, 42.42));
	tree.addLeaf(ft::make_pair(1, 42.42));
	tree.addLeaf(ft::make_pair(99, 42.42));
	tree.addLeaf(ft::make_pair(3256, 42.42));
	tree.addLeaf(ft::make_pair(4, 42.42));
	tree.printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Use printChildren() function with first key value (root):" << std::endl;
	tree.printChildren(ft::make_pair(5, 42.42));

	std::cout << std::endl;
	std::cout << "And another key value ([99, 42.42]):" << std::endl;
	tree.printChildren(ft::make_pair(99, 42.42));

	std::cout << std::endl;
}
