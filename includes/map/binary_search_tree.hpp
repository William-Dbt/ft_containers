#ifndef __BINARY_SEARCH_TREE_HPP__
# define __BINARY_SEARCH_TREE_HPP__

# include "utils.hpp"
# include "binary_search_tree_iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"

namespace	ft {
	template <class Key, class T, class Compare>
	class	BSTree {
		public:
			typedef ft::pair<Key, T>							value_type;
			typedef std::size_t									size_type;
			typedef Compare										key_compare;
			typedef ft::Node<Key, T>							node_type;
			typedef std::allocator< ft::Node<Key, T> >			node_alloc;
			typedef typename ft::Node<Key, T>::node_pointer		node_pointer;

			BSTree();
			BSTree(const value_type& data);
			virtual ~BSTree();

			void	printInOrder();
			void	deleteTree();

			int	getNodeHeight(node_pointer node) const;
			int	getBalanceFactor(node_pointer node) const;

			void			insertNode(const value_type& data);
			void			eraseNode(const value_type& data);
			node_pointer	findSmallest() const;
			node_pointer	findGreatest() const;
			node_pointer	findNode(const value_type& data) const;

			size_type	max_size() const;
			size_type	size() const;

			void	swap(BSTree& ref);

		private:
			int	_maxHeight(const int& lhs, const int& rhs);

			void	_printInOrder(node_pointer node);
			void	_removeSubTree(node_pointer node);
			void	_balanceTree(node_pointer node, bool erase);

			node_pointer	_leftRotate(node_pointer node);
			node_pointer	_rightRotate(node_pointer node);
			node_pointer	_rightLeftRotate(node_pointer node);
			node_pointer	_leftRightRotate(node_pointer node);
			node_pointer	_findSmallest(node_pointer node) const;
			node_pointer	_findGreatest(node_pointer node) const;

			node_pointer	_createNode(const value_type& data);
			node_pointer	_insertNode(node_pointer parent, node_pointer node, const value_type& data);
			// node_pointer	_eraseNode(node_pointer node, const value_type& data);
			void	_eraseNode(value_type data, node_pointer node);
			void	_eraseNode(node_pointer parent, node_pointer node, bool isLeft);
			void	_removeRootNode();

			node_pointer	_root;
			size_type		_size;
			node_alloc		_alloc;
			key_compare		_comp;
	};

	# include "binary_search_tree.tpp"
}

#endif
