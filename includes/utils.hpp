#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "is_integral.hpp"
# include "enable_if.hpp"

namespace	ft {
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);
}

# include "utils.tpp"

#endif
