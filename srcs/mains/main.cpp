#include <iostream>
#include <cstdlib>

#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / ((int)sizeof(Buffer) * 100))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}

// void	vectorTests();
// void	stackTests();
// void	mapTests();
// void	pairTests();
// void	BSTTests();

// static void	showIndex() {
// 	std::cout << "\033[33mList of tests to execute:" << std::endl;
// 	std::cout << "\033[93m";
// 	std::cout << " \'0\'\tVector tests" << std::endl;
// 	std::cout << " \'1\'\tStack tests" << std::endl;
// 	std::cout << " \'2\'\tMap tests" << std::endl;
// 	std::cout << " \'3\'\tPair tests" << std::endl;
// 	std::cout << " \'4\'\tBST tests" << std::endl;
// 	std::cout << "\033[31m";
// 	std::cout << "\'exit\'\tExit program" << std::endl;
// 	std::cout << "\033[33m";
// 	std::cout << "> ";
// }

// int	main() {
// 	std::string	idx;

// 	showIndex();
// 	while (std::getline(std::cin, idx)) {
// 		std::cout << std::endl;
// 		if (idx.compare("exit") == 0)
// 			break ;

// 		if (idx.size() == 0) {
// 			showIndex();
// 			continue ;
// 		}
// 		switch (atoi(idx.c_str())) {
// 			case 0: {
// 				vectorTests();
// 				break ;
// 			}
// 			case 1: {
// 				stackTests();
// 				break ;
// 			}
// 			case 2: {
// 				mapTests();
// 				break ;
// 			}
// 			case 3: {
// 				std::cout << "\033[0m";
// 				pairTests();
// 				break ;
// 			}
// 			case 4: {
// 				std::cout << "\033[0m";
// 				BSTTests();
// 				break ;
// 			}
// 			default:
// 				break ;
// 		}
// 		showIndex();
// 	}
// 	std::cout << "\033[0m";
// 	return 0;
// }
