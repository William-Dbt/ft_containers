#ifndef __RBTREE_HPP__
# define __RBTREE_HPP__

/* Node key 
- Root:		First top node
- Parent:	First related top node
- Child:	First related bottom nodes
- Leaf:		Lasts nodes (that don't have children)
*/

namespace	ft {
	template <class T>
	struct	node {
		typedef T		value_type;
		typedef node*	node_pointer;
		typedef node&	node_reference;

		node();
		node(const value_type& nKey, node_pointer nLeft = NULL, node_pointer nRight = NULL);
		node(const node & ref);

		virtual	~node();

		node_reference	operator=(const node & ref);

		// Variables
		value_type		key;
		node_pointer	left;	// Value => less than data
		node_pointer	right;	// Value => greater than data
	};

	template <class T>
	class	BSTree {
		public:
			typedef T									value_type;
			typedef std::allocator< ft::node<T> >		node_alloc;
			typedef typename ft::node<T>::node_pointer	node_pointer;

			BSTree();
			BSTree(const value_type& key);
			BSTree(const BSTree& ref);
			virtual	~BSTree();

			BSTree	operator=(const BSTree& ref);

			void	addLeaf(value_type key);
			void	printInOrder();
			void	printChildren(value_type key);
			void	removeNode(value_type key);

			node_pointer	findNode(value_type key);
			node_pointer	getRoot() const;
			node_pointer	findSmallest();

		private:
			node_pointer	createLeaf(value_type key);
			node_pointer	findNode(value_type key, node_pointer node);
			node_pointer	findSmallest(node_pointer node);
			node_pointer	copySubTree(node_pointer node);

			void	addLeaf(value_type key, node_pointer node);
			void	printInOrder(node_pointer node);
			void	removeNode(value_type key, node_pointer node);
			void	removeNode(node_pointer parent, node_pointer node, bool isLeft);
			void	removeRootNode();
			void	removeSubTree(node_pointer node);

			node_pointer	_root;
			node_alloc		_alloc;
	};
}

# include "binary_search_tree.tpp"

#endif
