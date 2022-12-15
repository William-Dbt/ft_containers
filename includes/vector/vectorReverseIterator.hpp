#ifndef __VECTORREVERSEITERATOR_HPP__
# define __VECTORREVERSEITERATOR_HPP__

// https://cplusplus.com/reference/iterator/RandomAccessIterator/
namespace	ft {
	template <class T>
	class	vectorReverseIterator {
		public:
			typedef				T								value_type;
			typedef				value_type*						pointer;
			typedef				value_type&						reference;
			typedef const		value_type&						const_reference;
			typedef typename	std::random_access_iterator_tag	category;
			typedef typename	std::ptrdiff_t					distance;

			vectorReverseIterator();
			vectorReverseIterator(pointer data);
			vectorReverseIterator(vectorReverseIterator const & ref);
			~vectorReverseIterator();
			
			operator		vectorReverseIterator<const T>() const;
			vectorReverseIterator&	operator=(vectorReverseIterator const & ref);
			vectorReverseIterator&	operator++();
			vectorReverseIterator	operator++(int);
			vectorReverseIterator&	operator--();
			vectorReverseIterator	operator--(int);

			reference		operator*();
			const_reference	operator*() const;
			pointer			operator->();
			pointer			operator->() const;
			reference		operator[](distance d);
			const_reference	operator[](distance d) const;

			bool	operator>(vectorReverseIterator const & ref) const;
			bool	operator<(vectorReverseIterator const & ref) const;
			bool	operator>=(vectorReverseIterator const & ref) const;
			bool	operator<=(vectorReverseIterator const & ref) const;
			bool	operator==(vectorReverseIterator const & ref) const;
			bool	operator!=(vectorReverseIterator const & ref) const;

		private:
			pointer	_data;
	};
}

# include "vectorReverseIterator.tpp"

#endif
