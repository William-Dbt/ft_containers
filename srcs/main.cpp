#include <iostream>
#include <vector>
#include "vector.hpp"

int	main() {
	ft::vector<int>		vec(2, 2);

	// vec[0] = 42;
	for (int i = 0; i < 3; i++)
		std::cout << vec[i] << std::endl;

	return 0;
}
