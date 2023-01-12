#ifndef __BINARY_SEARCH_TREE_ITERATOR_HPP__
# define __BINARY_SEARCH_TREE_ITERATOR_HPP__

namespace	ft {
	template <class T>
	class	bst_iterator {
		public:
			typedef T											value_type;
			typedef value_type*									pointer;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t						difference_type;

			bst_iterator();
			bst_iterator(const bst_iterator& ref);
			~bst_iterator();

			operator		bst_iterator<const T>() const;
			bst_iterator&	operator=(const bst_iterator& ref);

			bst_iterator&	operator++();
			bst_iterator	operator++(int);
			bst_iterator&	operator--();
			bst_iterator	operator--(int);

			reference	operator*();
			pointer		operator->();

			bool	operator==(bst_iterator<const T> const & ref);
			bool	operator!=(bst_iterator<const T> const & ref);

		private:
			pointer	_data;
	};
}

# include "binary_search_tree_iterator.tpp"

#endif
