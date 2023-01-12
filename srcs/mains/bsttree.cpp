#include <iostream>
#include "pair.hpp"
#include "binary_search_tree.hpp"

void	BSTTests() {
	ft::BSTree< ft::pair<int, float> >	tree;

	std::cout << "Create an empty binary tree and try to print values: ";
	tree.printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Now fill with values 10, 1, 99, 3256, 4 paired with 42.42 and print keys in order: ";
	tree.addLeaf(ft::pair<int, float>(5, 42.42));
	tree.addLeaf(ft::pair<int, float>(1, 42.42));
	tree.addLeaf(ft::pair<int, float>(99, 42.42));
	tree.addLeaf(ft::pair<int, float>(3256, 42.42));
	tree.addLeaf(ft::pair<int, float>(4, 42.42));
	tree.printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Use printChildren() function with first key value (root):" << std::endl;
	tree.printChildren(ft::pair<int, float>(5, 42.42));

	std::cout << std::endl;
	std::cout << "And another key value ([99, 42.42]):" << std::endl;
	tree.printChildren(ft::pair<int, float>(99, 42.42));

	std::cout << std::endl;
	std::cout << "Print children with getRoot() function:" << std::endl;
	tree.printChildren(tree.getRoot()->key);

	std::cout << std::endl;
	ft::BSTree< ft::pair<int, float> >::node_pointer	treeNode;

	std::cout << "Try to find the smallest node in the tree:" << std::endl;
	treeNode = tree.findSmallest();
	std::cout << "First: " << treeNode->key.first << " Second: " << treeNode->key.second << std::endl;

	std::cout << std::endl;
	std::cout << "Try to find the greatest node in the tree:" << std::endl;
	treeNode = tree.findGreatest();
	std::cout << "First: " << treeNode->key.first << " Second: " << treeNode->key.second << std::endl;

	std::cout << std::endl;
	std::cout << "Try to remove the [99, 42.42] key and print in order:" << std::endl;
	tree.removeNode(ft::pair<int, float>(99, 42.42));
	tree.printInOrder();

	std::cout << std::endl << std::endl;
	std::cout << "Try to delete the root [5, 42.42] and print in order:" << std::endl;
	tree.removeNode(ft::pair<int, float>(5, 42.42));
	tree.printInOrder();
	std::cout << "It works!" << std::endl;

	std::cout << std::endl;
	std::cout << "Try to remove key that is not in the tree: ";
	tree.removeNode(ft::pair<int, int>(5153, 461));

	std::cout << std::endl;
}
