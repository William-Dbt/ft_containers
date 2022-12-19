#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#					include <vector>
# include <memory>
# include <cstddef>
# include "utils.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"

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

			typedef typename ft::iterator<T>						iterator;
			typedef typename ft::iterator<const T>					const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			// Constructors, destructor & operator=>-----------------------------
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

			vector&	operator=(const vector& x);

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

			template <class InputIt>
			void		insert(iterator position, InputIt first, InputIt last);

			iterator	erase(iterator position);
			iterator	erase(iterator first, iterator last);
			void		swap(vector& x);
			void		clear();

			// Allocator>---------------------------------------------
			allocator_type	get_allocator() const;

		protected:
			pointer			_datas;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

			void	changeCapacity(size_type newCapacity);
	};

	template <class T, class Alloc>
	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

}

# include "vector.tpp"
# include "nonMemberFunctions.tpp"

#endif
