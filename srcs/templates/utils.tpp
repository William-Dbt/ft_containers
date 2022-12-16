template <class InputIt>
size_t	ft::distance(InputIt first, InputIt last) {
	size_t	size(0);
	
	while (first++ != last)
		size++;

	return size;
}

template <class InputIt1, class InputIt2>
bool	ft::lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
		if (*first1 < *first2)
			return true;

		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}
