template <class T>
ft::iterator<T>::iterator() : _data(NULL) {}

template <class T>
ft::iterator<T>::iterator(pointer data) : _data(data) {}

template <class T>
ft::iterator<T>::iterator(iterator const & ref) {
	this->_data = ref._data;
}

template <class T>
ft::iterator<T>::~iterator() {}

template <class T>
ft::iterator<T>::operator iterator<const T>() const
{
	return iterator<const T>(this->_data);
}

template <class T>
ft::iterator<T>&	ft::iterator<T>::operator=(iterator const & ref) {
	if (this != &ref)
		this->_data = ref._data;

	return *this;
}

template <class T>
ft::iterator<T>&	ft::iterator<T>::operator++() {
	this->_data++;
	return *this;
}

template <class T>
ft::iterator<T>	ft::iterator<T>::operator++(int) {
	iterator	tmp(this->_data);

	operator++();
	return tmp;
}

template <class T>
ft::iterator<T>&	ft::iterator<T>::operator--() {
	this->_data--;
	return *this;
}

template <class T>
ft::iterator<T>	ft::iterator<T>::operator--(int) {
	iterator	tmp(this->_data);

	operator--();
	return tmp;
}

template <class T>
ft::iterator<T>	ft::iterator<T>::operator+(int n) const {
	iterator	tmp(this->_data);

	tmp._data += n;
	return tmp;
}

template <class T>
ft::iterator<T>&	ft::iterator<T>::operator+=(int n) {
	this->_data += n;
	return (*this);
}

template <class T>
ft::iterator<T>	ft::iterator<T>::operator-(int n) const {
	iterator	tmp(this->_data);

	tmp._data -= n;
	return tmp;
}

template <class T>
ft::iterator<T>&	ft::iterator<T>::operator-=(int n) {
	this->_data -= n;
	return (*this);
}

template <class T>
typename ft::iterator<T>::reference	ft::iterator<T>::operator*() {
	return (*this->_data);
}

template <class T>
typename ft::iterator<T>::pointer	ft::iterator<T>::operator->() {
	return (&(this->operator*()));
}

template <class T>
typename ft::iterator<T>::reference	ft::iterator<T>::operator[](difference_type d) {
	return (*(this->_data + d));
}

template <class T>
bool	ft::iterator<T>::operator>(iterator const & ref) const {
	return (this->_data > ref._data);
}

template <class T>
bool	ft::iterator<T>::operator<(iterator const & ref) const {
	return (!(this->_data > ref._data));
}

template <class T>
bool	ft::iterator<T>::operator>=(iterator const & ref) const {
	return (this->_data >= ref._data);
}

template <class T>
bool	ft::iterator<T>::operator<=(iterator const & ref) const {
	return (this->_data <= ref._data);
}

template <class T>
bool	ft::iterator<T>::operator==(iterator const & ref) const {
	return (this->_data == ref._data);
}

template <class T>
bool	ft::iterator<T>::operator!=(iterator const & ref) const {
	return (this->_data != ref._data);
}

template <class Iterator>
typename ft::iterator<Iterator>::difference_type	ft::operator-(const ft::iterator<Iterator>& lhs, const ft::iterator<Iterator>& rhs) {
	ft::iterator<Iterator>								tmp(lhs);
	typename ft::iterator<Iterator>::difference_type	i = 0;

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
