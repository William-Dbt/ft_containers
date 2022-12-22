template <class T, class Container>
ft::stack<T, Container>::stack(const typename ft::stack<T, Container>::container_type & ctnr) : c(ctnr) {}

template <class T, class Container>
bool	ft::stack<T, Container>::empty() const {
	return (this->c.empty());
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type	ft::stack<T, Container>::size() const {
	return (this->c.size());
}

template <class T, class Container>
typename ft::stack<T, Container>::reference	ft::stack<T, Container>::top() {
	return (this->c.back());
}

template <class T, class Container>
typename ft::stack<T, Container>::const_reference	ft::stack<T, Container>::top() const {
	return (this->c.back());
}

template <class T, class Container>
void	ft::stack<T, Container>::push(const value_type& val) {
	this->c.push_back(val);
}

template <class T, class Container>
void	ft::stack<T, Container>::pop() {
	this->c.pop_back();
}

template <class T, class Container>
bool	operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c == rhs.c)
		return true;

	return false;
}

template <class T, class Container>
bool	operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c != rhs.c)
		return true;

	return false;
}	

template <class T, class Container>
bool	operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c < rhs.c)
		return true;

	return false;
}

template <class T, class Container>
bool	operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c <= rhs.c)
		return true;

	return false;
}

template <class T, class Container>
bool	operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c > rhs.c)
		return true;

	return false;
}

template <class T, class Container>
bool	operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	if (lhs.c >= rhs.c)
		return true;

	return false;
}
