#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <memory>
# include <cstddef>
# include "utils.hpp"
# include "vectorIterator.hpp"
# include "vectorReverseIterator.hpp"

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
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef typename ft::vectorIterator<T>				iterator;
			typedef typename ft::vectorIterator<const T>		const_iterator;
			typedef typename ft::vectorReverseIterator<T>		reverse_iterator;
			typedef typename ft::vectorReverseIterator<const T>	const_reverse_iterator;

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
			iterator				begin();
			const_iterator			begin() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;

			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			// Capacity>----------------------------------------------
			size_type	size() const;
			size_type	max_size() const;
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity() const;
			bool		empty() const;
			void		reserve(size_type n);
			// void		shrink_to_fit();	(C++11)

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

			void		assign(size_type n, const value_type& val);
			void		push_back(const value_type& val);
			void		pop_back();
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			/* template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last); */

			// Allocator>---------------------------------------------
			allocator_type	get_allocator() const;

		protected:
			pointer			_datas;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

			void	changeCapacity(size_type newCapacity);
	};
}

# include "vector.tpp"

#endif
