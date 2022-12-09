#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <memory>
# include <cstddef>
# include "utils.hpp"

namespace	ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// Typedefs>----------------------------------------------
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;

			// Constructors & Destructor>-----------------------------
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n,
							const value_type& value = value_type(),
							const allocator_type& alloc = allocator_type());

			template <class InputIt>
			vector(InputIt first, InputIt last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);

			vector(const vector& other);
			~vector();

			// Iterators>---------------------------------------------

			// Capacity>----------------------------------------------
			size_type	size() const;
			size_type	max_size() const;
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity() const;
			bool		empty() const;
			void		reserve(size_type n);
			void		shrink_to_fit();

			// Element Access>----------------------------------------
			reference			operator[](size_type n);
			const_reference		operator[](size_type n) const;
			reference			at(size_type n);
			const_reference		at(size_type n) const;
			reference			front();
			const_reference		front() const;
			reference			back();
			const_reference		back() const;
			value_type*			data();
			const value_type*	data() const;

			// Modifiers>---------------------------------------------
			template <class InputIt>
			void	assign(InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value,
												InputIt>::type* = NULL);

			void	assign(size_type n, const value_type& val);

			// Allocator>---------------------------------------------
			allocator_type	get_allocator() const;

		private:
			pointer			_datas;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

			void	changeCapacity(const size_type newCapacity);
	};
}

# include "vector.tpp"

#endif
