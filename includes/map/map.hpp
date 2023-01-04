#ifndef __MAP_HPP__
# define __MAP_HPP__

# include <memory>
# include "iterator_traits.hpp"

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map {
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef std::pair<const key_type, mapped_type>					value_type;
		typedef Compare													key_compare;
		// value_compare	Nested function class to compare elements	see value_comp
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		// iterator	a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator	a bidirectional iterator to const value_type	
		// reverse_iterator	reverse_iterator<iterator>	
		// const_reverse_iterator	reverse_iterator<const_iterator>
		// typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t													size_type;
};

#endif
