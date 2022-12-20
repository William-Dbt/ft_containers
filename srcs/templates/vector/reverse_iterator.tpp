template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : _iterator(NULL) {}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _iterator(it) {}

template <class Iterator>
template <class Iter>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base()) {}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type	ft::reverse_iterator<Iterator>::base() const {
	return this->_iterator;
}

template <class Iterator>
template <class Iter>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& ref) {
	this->_iterator = ref.base();
	return (*this);
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator+(difference_type n) const {
	reverse_iterator	rev_it(*this);

	rev_it += n;
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

	this->operator++();
	return rev_it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&	ft::reverse_iterator<Iterator>::operator+=(difference_type n) {
	this->_iterator -= n;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator-(difference_type n) const {
	reverse_iterator	rev_it(*this);

	rev_it -= n;
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

	this->operator--();
	return rev_it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&	ft::reverse_iterator<Iterator>::operator-=(difference_type n) {
	this->_iterator += n;
	return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator*() const {
	iterator_type	tmp = this->_iterator;

	return *--tmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer	ft::reverse_iterator<Iterator>::operator->() const {
	return &(operator*());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator[](difference_type n) const {
	return (this->base()[-n - 1]);
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

template <class Iterator1, class Iterator2>
bool	ft::operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool	ft::operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool	ft::operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool	ft::operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool	ft::operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool	ft::operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	reverse_iterator<Iterator>	tmp(rev_it);

	tmp += n;
	return tmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type	ft::operator-(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	ft::reverse_iterator<Iterator>								tmp(lhs);
	typename ft::reverse_iterator<Iterator>::difference_type	i = 0;

	if (rhs == lhs)
		return 0;

	if (tmp > rhs) {
		while (tmp-- != rhs)
			i++;
	}
	else
		while (tmp++ != rhs)
			i--;

	return i;
}
