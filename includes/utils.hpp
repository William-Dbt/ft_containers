#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "is_integral.hpp"
# include "enable_if.hpp"

namespace	ft {
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);

	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);
}

# include "utils.tpp"

#endif
