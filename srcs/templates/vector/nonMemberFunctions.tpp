template <class T, class Alloc>
bool	ft::operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	size_t	i;

	if (lhs.size() != rhs.size())
		return false;

	for (i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;

	return true;
}

template <class T, class Alloc>
bool	ft::operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	ft::operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool	ft::operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool	ft::operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	ft::operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}
