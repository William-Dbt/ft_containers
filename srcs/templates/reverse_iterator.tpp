template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : _iterator() {}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _iterator(it) {}

template <class Iterator>
template <class Iter>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base()) {}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type	ft::reverse_iterator<Iterator>::base() const {
	return iterator_type(this->_iterator);
}

template <class Iterator>
template <class Iter>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& ref) {
	this->_iterator = ref.base();
	return *this;
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

	return *(--tmp);
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer	ft::reverse_iterator<Iterator>::operator->() const {
	return &(this->operator*());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator[](difference_type n) const {
	return (this->base()[ -n - 1]);
}

// Relational && Extern Operators
template <class Iterator>
bool	operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool	operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool	operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool	operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool	operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool	operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool	operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
ft::reverse_iterator<Iterator>	operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
	return (ft::reverse_iterator<Iterator>(rev_it.base() - n));
}

template <class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type	operator-(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
	return (rhs.base() - lhs.base());
}
