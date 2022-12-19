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
			reverse_iterator	(const reverse_iterator<Iter>& rev_it);

			iterator_type	base() const;

			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			reverse_iterator&	operator+=(difference_type n);
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator&	operator--();
			reverse_iterator	operator--(int);
			reverse_iterator&	operator-= (difference_type n);

			reference	operator*() const;
			pointer 	operator->() const;

		private:
			iterator_type	_iterator;
	};

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

	template <class Iterator>
	typename	reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
}

# include "reverse_iterator.tpp"

#endif
