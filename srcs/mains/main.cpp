#include <iostream>
#include <cstdlib>

void	vectorTests();
void	stackTests();
void	mapTests();
void	pairTests();
void	BSTTests();

static void	showIndex() {
	std::cout << "\033[33mList of tests to execute:" << std::endl;
	std::cout << "\033[93m";
	std::cout << " \'0\'\tVector tests" << std::endl;
	std::cout << " \'1\'\tStack tests" << std::endl;
	std::cout << " \'2\'\tMap tests" << std::endl;
	std::cout << " \'3\'\tPair tests" << std::endl;
	std::cout << " \'4\'\tBST tests" << std::endl;
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
			case 1: {
				stackTests();
				break ;
			}
			case 2: {
				mapTests();
				break ;
			}
			case 3: {
				std::cout << "\033[0m";
				pairTests();
				break ;
			}
			case 4: {
				std::cout << "\033[0m";
				BSTTests();
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
