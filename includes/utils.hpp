#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "is_integral.hpp"
# include "enable_if.hpp"
# include "pair.hpp"

namespace	ft {
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);

	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);

	template <class Key, class T>
	struct	Node {
		// typedef T		value_type;
		typedef pair<Key, T>	value_type;
		typedef Node*			node_pointer;
		typedef Node&			node_reference;

		Node();
		Node(const value_type& vData);
		virtual	~Node();

		value_type		data;
		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		int				height;
	};

	# include "utils.tpp"
}


#endif
