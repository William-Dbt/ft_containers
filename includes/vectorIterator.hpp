#ifndef __VECTORITERATOR_HPP__
# define __VECTORITERATOR_HPP__

// https://cplusplus.com/reference/iterator/RandomAccessIterator/
namespace	ft {
	template <class T>
	class	vectorIterator {
		public:
			typedef T*											pointer;
			typedef T&											reference;
			typedef typename std::random_access_iterator_tag	category;
			typedef typename std::ptrdiff_t						distance;

			vectorIterator();
			vectorIterator(pointer data);
			vectorIterator(vectorIterator const & ref);
			~vectorIterator();
			
			vectorIterator&	operator=(vectorIterator const & ref);
			vectorIterator&	operator++();
			vectorIterator	operator++(int);
			vectorIterator&	operator--();
			vectorIterator	operator--(int);

			reference		operator*();
			pointer			operator->();

			bool	operator>(vectorIterator const & ref) const;
			bool	operator<(vectorIterator const & ref) const;
			bool	operator>=(vectorIterator const & ref) const;
			bool	operator<=(vectorIterator const & ref) const;
			bool	operator==(vectorIterator const & ref) const;
			bool	operator!=(vectorIterator const & ref) const;

		private:
			pointer	_data;
	};
}

# include "vectorIterator.tpp"

#endif
