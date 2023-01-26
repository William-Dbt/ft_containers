#ifndef __RBTREE_HPP__
# define __RBTREE_HPP__

# include <cstdlib>
# include "binary_search_tree_iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"

namespace	ft {
	/* Node key 
	- Root:		First top node
	- Parent:	First related top node
	- Child:	First related bottom nodes
	- Leaf:		Lasts nodes (that don't have children)
	*/
	template <class T>
	struct	node {
		typedef T		value_type;
		typedef node*	node_pointer;
		typedef node&	node_reference;

		node();
		node(const value_type& nKey, node_pointer nParent = NULL, node_pointer nLeft = NULL, node_pointer nRight = NULL);
		node(const node & ref);

		virtual	~node();

		node_reference	operator=(const node & ref);

		// Variables
		value_type		key;
		node_pointer	parent;	// Ptr before node
		node_pointer	left;	// Value => less than key
		node_pointer	right;	// Value => greater than key
	};

	template <class T>
	class	BSTree {
		public:
			typedef T											value_type;
			typedef ft::node<value_type>						node_type;
			typedef std::allocator< ft::node<value_type> >		node_alloc;
			typedef typename ft::node<value_type>::node_pointer	node_pointer;
			typedef ft::bst_iterator<node_type>					iterator;
			typedef ft::bst_iterator<const node_type>			const_iterator;

			BSTree();
			BSTree(const value_type& key);
			virtual	~BSTree();

			void	addLeaf(value_type key);
			void	printInOrder();
			void	printChildren(value_type key);
			void	removeNode(value_type key);
			void	deleteTree();
			void	swap(BSTree& ref);

			node_pointer	findNode(value_type key) const;
			node_pointer	getRoot() const;
			node_pointer	findSmallest() const;
			node_pointer	findGreatest() const;

			size_t	max_size() const;

		private:
			node_pointer	_createLeaf(value_type key);
			node_pointer	_findSmallest(node_pointer node) const;
			node_pointer	_findGreatest(node_pointer node) const;

			void	_balanceTree();
			void	_printInOrder(node_pointer node);
			void	_removeNode(value_type key, node_pointer node);
			void	_removeNode(node_pointer parent, node_pointer node, bool isLeft);
			void	_removeRootNode();
			void	_removeSubTree(node_pointer node);

			node_pointer		_root;
			node_alloc			_alloc;
			// This pair element refers to the number on the left and on the right of the tree
			ft::pair<unsigned long int, unsigned long int>	_nbElements;
	};

	# include "binary_search_tree.tpp"
}

#endif
