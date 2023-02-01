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

	template <class T, class Compare>
	class	BSTree {
		public:
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef ft::Node<value_type>						node_type;
			typedef std::allocator< ft::Node<value_type> >		node_alloc;
			typedef typename ft::Node<value_type>::node_pointer	node_pointer;
			typedef ft::bst_iterator<node_type>					iterator;
			typedef ft::bst_iterator<const node_type>			const_iterator;

			BSTree();
			BSTree(const value_type& data);
			~BSTree();

			void	printInOrder();
			void	deleteTree();

			int	getNodeHeight(node_pointer node) const;
			int	getBalanceFactor(node_pointer node) const;

			void			insertNode(const value_type& data);
			void			eraseNode(const value_type& data);
			node_pointer	findSmallest() const;
			node_pointer	findGreatest() const;
			node_pointer	findNode(const value_type& data) const;

			size_t	max_size() const;

			void	swap(BSTree& ref);

		private:
			void	_printInOrder(node_pointer node);
			void	_removeSubTree(node_pointer node);
			void	_balanceTree(node_pointer node, bool erase);

			node_pointer	_leftRotate(node_pointer node);
			node_pointer	_rightRotate(node_pointer node);
			node_pointer	_findSmallest(node_pointer node) const;
			node_pointer	_findGreatest(node_pointer node) const;

			node_pointer	_createNode(const value_type& data);
			node_pointer	_insertNode(node_pointer parent, node_pointer node, const value_type& data);
			node_pointer	_eraseNode(node_pointer node, const value_type& data);

			node_pointer	_root;
			node_alloc		_alloc;
			key_compare		_comp;
	};

	# include "binary_search_tree.tpp"
}

#endif
