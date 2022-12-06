/* integral types
bool
char
char16_t
char32_t
wchar_t
signed char
short int
int
long int
long long int
unsigned char
unsigned short int
unsigned int
unsigned long int
unsigned long long int */

#ifndef __IS_INTEGRAL_HPP__
# define __IS_INTEGRAL_HPP__

# include <type_traits>

namespace	ft {
	template <class T>
	struct	is_integral : public integral_constant {
		
	};
}

#endif
