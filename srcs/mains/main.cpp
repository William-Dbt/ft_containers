#include <iostream>
#include <cstdlib>

void	vectorTests();

static void	showIndex() {
	std::cout << "\033[33mList of tests to execute:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tVector Tests" << std::endl;
	std::cout << "\033[31m";
	std::cout << "\'exit\'\tExit program" << std::endl;
	std::cout << "\033[33m";
	std::cout << "> ";
}

int	main() {
	std::string	idx;

	showIndex();
	while (std::getline(std::cin, idx)) {
		std::cout << std::endl;
		if (idx.compare("exit") == 0)
			break ;

		if (idx.size() == 0) {
			showIndex();
			continue ;
		}
		switch (atoi(idx.c_str())) {
			case 0: {
				vectorTests();
				break ;
			}
			default:
				break ;
		}
		showIndex();
	}
	std::cout << "\033[0m";
	return 0;
}
