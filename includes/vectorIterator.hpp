#ifndef __VECTORITERATOR_HPP__
# define __VECTORITERATOR_HPP__

// https://cplusplus.com/reference/iterator/RandomAccessIterator/
namespace	ft {
	template <class T>
	class	vectorIterator {
		public:
			typedef	T											value_type;
			typedef value_type*									pointer;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
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
			const_reference	operator*() const;
			pointer			operator->();
			pointer			operator->() const;
			reference		operator[](distance d);
			const_reference	operator[](distance d) const;

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
