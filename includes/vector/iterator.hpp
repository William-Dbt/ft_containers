#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

namespace	ft {
	template <class T>
	class	iterator {
		public:
			typedef				T								value_type;
			typedef				value_type*						pointer;
			typedef				value_type&						reference;
			typedef const		value_type&						const_reference;
			typedef typename	std::random_access_iterator_tag	iterator_category;
			typedef typename	std::ptrdiff_t					difference_type;

			iterator();
			iterator(pointer data);
			iterator(iterator const & ref);
			~iterator();
			
			operator	iterator<const T>() const;
			iterator&	operator=(iterator const & ref);
			iterator&	operator++();
			iterator	operator++(int);
			iterator&	operator--();
			iterator	operator--(int);

			iterator	operator+(int n) const;
			iterator&	operator+=(int n);
			iterator	operator-(int n) const;
			iterator&	operator-=(int n);

			reference	operator*();
			pointer		operator->();
			reference	operator[](difference_type d);

			bool	operator>(iterator const & ref) const;
			bool	operator<(iterator const & ref) const;
			bool	operator>=(iterator const & ref) const;
			bool	operator<=(iterator const & ref) const;
			bool	operator==(iterator const & ref) const;
			bool	operator!=(iterator const & ref) const;

		private:
			pointer	_data;
	};
}

# include "iterator.tpp"

#endif
