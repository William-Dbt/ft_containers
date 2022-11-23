#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <memory>
# include <cstddef>

namespace	ft {
	template < typename T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// Typedefs>----------------------------------------------
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef std::size_t									size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;

			// Constructors & Destructor>-----------------------------
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n,
							const value_type& value = T(),
							const allocator_type& alloc = allocator_type());

			template <class InputIt>
			vector(InputIt first, InputIt last,
					const allocator_type& alloc = allocator_type());

			vector(const vector& other);
			~vector();

			// Elements Access>---------------------------------------
			reference&			operator[](size_type n);
			const_reference&	operator[](size_type n) const;

		private:
			pointer			_datas;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			
	};
}

# include "vector.tpp"

#endif
