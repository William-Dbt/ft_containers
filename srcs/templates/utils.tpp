template <class InputIt>
size_t	ft::distance(InputIt first, InputIt last) {
	size_t	size(0);
	
	while (first++ != last)
		size++;

	return size;
}
