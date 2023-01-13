/* MEMBERS FUNCTIONS */
template <class T1, class T2>
ft::pair<T1, T2>::pair() : first(T1()), second(T2()) {}

template <class T1, class T2>
ft::pair<T1, T2>::pair(const first_type& a, const second_type& b) : first(a), second(b) {}

template <class T1, class T2>
template <class U1, class U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second) {}

template <class T1, class T2>
ft::pair<T1, T2>&	ft::pair<T1, T2>::operator=(const pair& ref) {
	if (this != &ref) {
		this->first = ref.first;
		this->second = ref.second;
	}
	return (*this);
}

/* NON-MEMBER FUNCTIONS */
template <class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 a, T2 b) {
	return (ft::pair<T1, T2>(a, b));
}

template <class T1, class T2>
bool	operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool	operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool	operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool	operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool	operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (rhs < lhs);
}

template <class T1, class T2>
bool	operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
	return (!(lhs < rhs));
}

template <class T1, class T2>
std::ostream&	operator<<(std::ostream& stream, const ft::pair<T1, T2>& ref) {
	stream << '[' << ref.first << ", " << ref.second << ']';
	return stream;
}
