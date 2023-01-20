#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "vector.hpp"

namespace	ft {
	template < class T, class Container = ft::vector<T> >
	class	stack {
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			explicit	stack(const container_type& ctnr = container_type());

			bool			empty() const;
			size_type		size() const;
			reference		top();
			const_reference	top() const;
			void			push(const value_type& val);
			void			pop();

			template <class Tn, class Containern>
			friend bool	operator==(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

			template <class Tn, class Containern>
			friend bool	operator!=(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

			template <class Tn, class Containern>
			friend bool	operator<(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

			template <class Tn, class Containern>
			friend bool	operator<=(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

			template <class Tn, class Containern>
			friend bool	operator>(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

			template <class Tn, class Containern>
			friend bool	operator>=(const ft::stack<Tn,Containern>& lhs, const ft::stack<Tn,Containern>& rhs);

		protected:
			container_type	c;
	};

	# include "stack.tpp"
}

#endif
