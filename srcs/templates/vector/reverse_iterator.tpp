template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : _iterator(NULL) {}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _iterator(it) {}

template <class Iterator>
template <class Iter>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) : _iterator(rev_it._iterator) {}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type	ft::reverse_iterator<Iterator>::base() const {
	return this->_iterator;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator+(difference_type n) const {
	reverse_iterator	rev_it(*this);

	rev_it -= n;
	return rev_it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&	ft::reverse_iterator<Iterator>::operator++() {
	this->_iterator--;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator++(int) {
	reverse_iterator	rev_it(*this);

	this->operator++;
	return rev_it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator-(difference_type n) const {
	reverse_iterator	rev_it(*this);

	rev_it += n;
	return rev_it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&	ft::reverse_iterator<Iterator>::operator--() {
	this->_iterator++;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator--(int) {
	reverse_iterator	rev_it(*this);

	this->operator--;
	return rev_it;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator*() const {
	iterator_type	tmp = this->_iterator;

	return *tmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer	ft::reverse_iterator<Iterator>::operator->() const {
	return &(operator*());
}

template <class Iterator>
bool	ft::operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool	ft::operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool	ft::operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool	ft::operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool	ft::operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool	ft::operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
}
