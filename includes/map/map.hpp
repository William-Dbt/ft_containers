#ifndef __MAP_HPP__
# define __MAP_HPP__

# include <memory>
# include "binary_search_tree.hpp"
# include "pair.hpp"
# include "iterator_traits.hpp"
# include "binary_search_tree_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef size_t													size_type;
			typedef Compare													key_compare;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::bst_iterator<T>							iterator;
			typedef typename ft::bst_iterator<const T>						const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

			class	value_compare {// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}	// constructed with map's comparison object
			};

			// Constructors, destructor & operator=
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& ref);

			template <class InputIt>
			map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			~map();
			map&	operator=(const map& ref);

		private:
			ft::BSTree<value_type>	_tree;
			size_type				_size;
			key_compare				_comp;
			allocator_type			_alloc;
	};
}

# include "map.tpp"

#endif
