#ifndef __MAP_HPP__
# define __MAP_HPP__

# include <memory>
# include <stdexcept>
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
			typedef ft::pair<key_type, mapped_type>							value_type;
			typedef size_t													size_type;
			typedef Compare													key_compare;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::BSTree<value_type>::iterator				iterator;
			typedef typename ft::BSTree<value_type>::const_iterator			const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

			class	value_compare {
				friend class map;
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
			};

			// Constructors, destructor & operator=
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& ref);

			template <class InputIt>
			map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			~map();
			map&	operator=(const map& ref);

			// Iterators
			iterator		begin();
			const_iterator	begin() const;

			iterator		end();
			const_iterator	end() const;

			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;

			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			// Capacity
			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;

			// Access
			mapped_type&		operator[](const key_type& k);
			mapped_type&		at(const key_type& k);
			const mapped_type&	at(const key_type& k) const;

			// Modifiers
			ft::pair<iterator, bool>	insert(const value_type& value);
			iterator					insert(iterator pos, const value_type& value);

			template <class InputIt>
			void	insert(InputIt first, InputIt last);

			void		erase(iterator position);
			size_type	erase(const key_type& k);
			void		erase(iterator first, iterator last);
			void		swap(map& x);
			void		clear();

			// Observers
			key_compare		key_comp() const;
			value_compare	value_comp() const;

			// Operations
			iterator									find(const key_type& k);
			const_iterator								find(const key_type& k) const;
			size_type									count(const key_type& k) const;
			iterator									lower_bound(const key_type& k);
			const_iterator								lower_bound(const key_type& k) const;
			iterator									upper_bound(const key_type& k);
			const_iterator								upper_bound(const key_type& k) const;

			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}
			ft::pair<iterator, iterator>				equal_range(const key_type& k) {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			// Allocator
			allocator_type	get_allocator() const;

			// TODO - Remove from public
			ft::BSTree<value_type>	_tree;
		private:
			size_type				_size;
			key_compare				_comp;
			allocator_type			_alloc;
	};

	# include "map.tpp"
}

#endif
