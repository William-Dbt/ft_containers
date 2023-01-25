#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__

# include "iterator_traits.hpp"

namespace	ft {
	template <class Iterator>
	class	reverse_iterator {
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator();
			explicit reverse_iterator(iterator_type it);

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it);

			iterator_type	base() const;

			template <class Iter>
			reverse_iterator	&operator=(const reverse_iterator<Iter>& other);

			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			reverse_iterator&	operator+=(difference_type n);
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator&	operator--();
			reverse_iterator	operator--(int);
			reverse_iterator&	operator-=(difference_type n);

			reference	operator*() const;
			pointer 	operator->() const;
			reference	operator[](difference_type n) const;

		private:
			iterator_type	_iterator;
	};

	# include "reverse_iterator.tpp"
}

#endif
