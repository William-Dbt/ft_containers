template <class T>
ft::vectorIterator<T>::vectorIterator() : _data(NULL) {}

template <class T>
ft::vectorIterator<T>::vectorIterator(pointer data) : _data(data) {}

template <class T>
ft::vectorIterator<T>::vectorIterator(vectorIterator const & ref) {
	this->_data = ref._data;
}

template <class T>
ft::vectorIterator<T>::~vectorIterator() {}

template <class T>
ft::vectorIterator<T>&	ft::vectorIterator<T>::operator=(vectorIterator const & ref) {
	if (this != &ref)
		this->_data = ref._data;

	return *this;
}

template <class T>
ft::vectorIterator<T>&	ft::vectorIterator<T>::operator++() {
	this->_data++;
	return *this;
}

template <class T>
ft::vectorIterator<T>	ft::vectorIterator<T>::operator++(int) {
	vectorIterator	tmp(*this);

	operator++();
	return tmp;
}

template <class T>
ft::vectorIterator<T>&	ft::vectorIterator<T>::operator--() {
	this->_data--;
	return *this;
}

template <class T>
ft::vectorIterator<T>	ft::vectorIterator<T>::operator--(int) {
	vectorIterator	tmp(*this);

	operator--();
	return tmp;
}

template <class T>
typename ft::vectorIterator<T>::reference	ft::vectorIterator<T>::operator*() {
	return (*this->_data);
}

template <class T>
typename ft::vectorIterator<T>::const_reference	ft::vectorIterator<T>::operator*() const {
	return (*this->_data);
}

template <class T>
typename ft::vectorIterator<T>::pointer	ft::vectorIterator<T>::operator->() {
	return (&this->_data);
}

template <class T>
typename ft::vectorIterator<T>::pointer	ft::vectorIterator<T>::operator->() const {
	return (&this->_data);
}

template <class T>
typename ft::vectorIterator<T>::reference	ft::vectorIterator<T>::operator[](distance d) {
	return (*(this->_data + d));
}

template <class T>
typename ft::vectorIterator<T>::const_reference	ft::vectorIterator<T>::operator[](distance d) const {
	return (*(this->_data + d));
}

template <class T>
bool	ft::vectorIterator<T>::operator>(vectorIterator const & ref) const {
	return (this->_data > ref._data);
}

template <class T>
bool	ft::vectorIterator<T>::operator<(vectorIterator const & ref) const {
	return (!(this->_data > ref._data));
}

template <class T>
bool	ft::vectorIterator<T>::operator>=(vectorIterator const & ref) const {
	return (this->_data >= ref._data);
}

template <class T>
bool	ft::vectorIterator<T>::operator<=(vectorIterator const & ref) const {
	return (this->_data <= ref._data);
}

template <class T>
bool	ft::vectorIterator<T>::operator==(vectorIterator const & ref) const {
	return (this->_data == ref._data);
}

template <class T>
bool	ft::vectorIterator<T>::operator!=(vectorIterator const & ref) const {
	return (!(this->_data == ref._data));
}
