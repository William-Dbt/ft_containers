#ifndef __VECTORCONSTITERATOR_HPP__
# define __VECTORCONSTITERATOR_HPP__

// https://cplusplus.com/reference/iterator/RandomAccessIterator/
namespace	ft {
	template <class T>
	class	vectorConstIterator {
		public:
			typedef	T											value_type;
			typedef value_type*									pointer;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename std::random_access_iterator_tag	category;
			typedef typename std::ptrdiff_t						distance;

			vectorConstIterator();
			vectorConstIterator(pointer data);
			vectorConstIterator(vectorConstIterator const & ref);
			~vectorConstIterator();
			
			vectorConstIterator&	operator=(vectorConstIterator const & ref);
			vectorConstIterator&	operator++();
			vectorConstIterator	operator++(int);
			vectorConstIterator&	operator--();
			vectorConstIterator	operator--(int);

			reference		operator*();
			const_reference	operator*() const;
			pointer			operator->();
			pointer			operator->() const;
			reference		operator[](distance d);
			const_reference	operator[](distance d) const;

			bool	operator>(vectorConstIterator const & ref) const;
			bool	operator<(vectorConstIterator const & ref) const;
			bool	operator>=(vectorConstIterator const & ref) const;
			bool	operator<=(vectorConstIterator const & ref) const;
			bool	operator==(vectorConstIterator const & ref) const;
			bool	operator!=(vectorConstIterator const & ref) const;

		private:
			pointer	_data;
	};
}

# include "vectorConstIterator.tpp"

#endif
