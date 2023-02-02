#ifndef __BINARY_SEARCH_TREE_ITERATOR_HPP__
# define __BINARY_SEARCH_TREE_ITERATOR_HPP__

namespace	ft {
	template <class T>
	class	bst_iterator {
		public:
			typedef typename T::value_type						value_type;
			typedef const value_type*							pointer;
			typedef const value_type&							reference;
			typedef T											node;
			typedef T*											node_pointer;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t						difference_type;

			bst_iterator();
			bst_iterator(node_pointer data, node_pointer parent);
			bst_iterator(const bst_iterator& ref);
			~bst_iterator();

			operator		bst_iterator<const T>() const;
			bst_iterator&	operator=(const bst_iterator& ref);

			bst_iterator&	operator++();
			bst_iterator	operator++(int);
			bst_iterator&	operator--();
			bst_iterator	operator--(int);

			reference	operator*() const;
			value_type*	operator->();
			pointer		operator->() const;

			bool	operator==(bst_iterator<const T> const & ref);
			bool	operator!=(bst_iterator<const T> const & ref);

			node_pointer	_data;
			// In case of sending NULL in _data (as end iterator) or iterator outside the tree
			node_pointer	_parent;
	};
}

# include "binary_search_tree_iterator.tpp"

#endif
