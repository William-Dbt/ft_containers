#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <memory>

namespace	ft {
	template < typename T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// Constructors
			vector();
			// explicit vector(const Allocator& alloc);
			// explicit vector(size_t count,
			// 				const T& value = T(),
			// 				const Allocator& alloc = Allocator());

			// template < class InputIt >
			// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());

			// vector(const vector& other);
			// ----------------------------------------

		private:
			static T			value_type;
			static Allocator	allocator_type;
	};
}

# include "vector.tpp"

#endif
