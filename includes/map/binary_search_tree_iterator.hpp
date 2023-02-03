#ifndef __BINARY_SEARCH_TREE_ITERATOR_HPP__
# define __BINARY_SEARCH_TREE_ITERATOR_HPP__

# include "pair.hpp"

namespace	ft {
	template <class Key, class T>
	class	bst_iterator {
		public:
			// typedef typename T::value_type						value_type;
			// typedef const value_type*							pointer;
			// typedef const value_type&							reference;
			// typedef T											node;
			// typedef T*											node_pointer;

			typedef ft::pair<Key, T>							value_type;
			typedef value_type*									pointer;
			typedef value_type&									reference;
			typedef ft::Node<Key, T>*							node_pointer;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t						difference_type;

			bst_iterator();
			bst_iterator(node_pointer data, node_pointer parent);
			bst_iterator(const bst_iterator& ref);

			// template <class InputIt>
			// bst_iterator(const InputIt& ref);

			~bst_iterator();

			// operator		bst_iterator<Key, T>() const;
			bst_iterator&	operator=(const bst_iterator& ref);

			template <class InputIt>
			bst_iterator&	operator=(const InputIt& ref);

			bst_iterator&	operator++();
			bst_iterator	operator++(int);
			bst_iterator&	operator--();
			bst_iterator	operator--(int);

			reference	operator*() const;
			pointer		operator->() const;

			bool	operator==(bst_iterator<Key, T> const & ref);
			bool	operator!=(bst_iterator<Key, T> const & ref);

			template <class InputIt>
			bool	operator==(InputIt const & ref);

			template <class InputIt>
			bool	operator!=(InputIt const & ref);

			node_pointer	_data;
			// In case of sending NULL in _data (as end iterator) or iterator outside the tree
			node_pointer	_parent;
	};

	template <class Key, class T>
	class	const_bst_iterator {
		public:
			// typedef typename T::value_type						value_type;
			// typedef const value_type*							pointer;
			// typedef const value_type&							reference;
			// typedef T											node;
			// typedef T*											node_pointer;

			typedef ft::pair<Key, T>							value_type;
			typedef const value_type*							pointer;
			typedef const value_type&							reference;
			typedef ft::Node<Key, T>*							node_pointer;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t						difference_type;

			const_bst_iterator();
			const_bst_iterator(node_pointer data, node_pointer parent);
			const_bst_iterator(const const_bst_iterator& ref);

			template <class InputIt>
			const_bst_iterator(const InputIt& ref);

			~const_bst_iterator();

			// operator		const_bst_iterator<Key, T>() const;
			const_bst_iterator&	operator=(const const_bst_iterator& ref);

			template <class InputIt>
			const_bst_iterator&	operator=(const InputIt& ref);

			const_bst_iterator&	operator++();
			const_bst_iterator	operator++(int);
			const_bst_iterator&	operator--();
			const_bst_iterator	operator--(int);

			reference	operator*() const;
			pointer		operator->() const;

			bool	operator==(const_bst_iterator<Key, T> const & ref);
			bool	operator!=(const_bst_iterator<Key, T> const & ref);

			template <class InputIt>
			bool	operator==(InputIt const & ref);

			template <class InputIt>
			bool	operator!=(InputIt const & ref);

			node_pointer	_data;
			// In case of sending NULL in _data (as end iterator) or iterator outside the tree
			node_pointer	_parent;
	};

	# include "binary_search_tree_iterator.tpp"
}

#endif
