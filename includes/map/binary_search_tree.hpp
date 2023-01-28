#ifndef __BINARY_SEARCH_TREE_HPP__
# define __BINARY_SEARCH_TREE_HPP__

# include "binary_search_tree_iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"

namespace	ft {
	template <class T>
	struct	Node {
		typedef T		value_type;
		typedef Node*	node_pointer;
		typedef Node&	node_reference;

		Node();
		Node(const value_type& vData);
		virtual	~Node();

		value_type		data;
		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		int				height;
	};

	template <class T>
	class	BSTree {
		public:
			typedef T											value_type;
			typedef ft::Node<value_type>						node_type;
			typedef std::allocator< ft::Node<value_type> >		node_alloc;
			typedef typename ft::Node<value_type>::node_pointer	node_pointer;
			typedef ft::bst_iterator<node_type>					iterator;
			typedef ft::bst_iterator<const node_type>			const_iterator;

			BSTree();
			BSTree(const value_type& data);
			~BSTree();

			node_pointer	insert(const value_type& data);
			
			// node_pointer	find(const value_type& data) const;

		private:
			int	_maxHeight(const int& lhs, const int& rhs) const;
			int	_getNodeHeight(node_pointer node) const;
			int	_getBalanceFactor(node_pointer node) const;

			// Operations
			node_pointer	_leftRotate(node_pointer node);
			node_pointer	_rightRotate(node_pointer node);

			node_pointer	_createNode(const value_type& data);
			node_pointer	_insert(node_pointer node, const value_type& data);

			node_pointer	_root;
			node_alloc		_alloc;
	};

	# include "binary_search_tree.tpp"
}

#endif
