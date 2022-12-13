template <class T>
ft::vectorConstIterator<T>::vectorConstIterator() : _data(NULL) {}

template <class T>
ft::vectorConstIterator<T>::vectorConstIterator(pointer data) : _data(data) {}

template <class T>
ft::vectorConstIterator<T>::vectorConstIterator(vectorConstIterator const & ref) {
	this->_data = ref._data;
}

template <class T>
ft::vectorConstIterator<T>::~vectorConstIterator() {}

template <class T>
ft::vectorConstIterator<T>&	ft::vectorConstIterator<T>::operator=(vectorConstIterator const & ref) {
	if (this != &ref)
		this->_data = ref._data;

	return *this;
}

template <class T>
ft::vectorConstIterator<T>&	ft::vectorConstIterator<T>::operator++() {
	this->_data++;
	return *this;
}

template <class T>
ft::vectorConstIterator<T>	ft::vectorConstIterator<T>::operator++(int) {
	vectorConstIterator	tmp(*this);

	operator++();
	return tmp;
}

template <class T>
ft::vectorConstIterator<T>&	ft::vectorConstIterator<T>::operator--() {
	this->_data--;
	return *this;
}

template <class T>
ft::vectorConstIterator<T>	ft::vectorConstIterator<T>::operator--(int) {
	vectorConstIterator	tmp(*this);

	operator--();
	return tmp;
}

template <class T>
typename ft::vectorConstIterator<T>::reference	ft::vectorConstIterator<T>::operator*() {
	return (*this->_data);
}

template <class T>
typename ft::vectorConstIterator<T>::const_reference	ft::vectorConstIterator<T>::operator*() const {
	return (*this->_data);
}

template <class T>
typename ft::vectorConstIterator<T>::pointer	ft::vectorConstIterator<T>::operator->() {
	return (&this->_data);
}

template <class T>
typename ft::vectorConstIterator<T>::pointer	ft::vectorConstIterator<T>::operator->() const {
	return (&this->_data);
}

template <class T>
typename ft::vectorConstIterator<T>::reference	ft::vectorConstIterator<T>::operator[](distance d) {
	return (*(this->_data + d));
}

template <class T>
typename ft::vectorConstIterator<T>::const_reference	ft::vectorConstIterator<T>::operator[](distance d) const {
	return (*(this->_data + d));
}

template <class T>
bool	ft::vectorConstIterator<T>::operator>(vectorConstIterator const & ref) const {
	return (this->_data > ref._data);
}

template <class T>
bool	ft::vectorConstIterator<T>::operator<(vectorConstIterator const & ref) const {
	return (!(this->_data > ref._data));
}

template <class T>
bool	ft::vectorConstIterator<T>::operator>=(vectorConstIterator const & ref) const {
	return (this->_data >= ref._data);
}

template <class T>
bool	ft::vectorConstIterator<T>::operator<=(vectorConstIterator const & ref) const {
	return (this->_data <= ref._data);
}

template <class T>
bool	ft::vectorConstIterator<T>::operator==(vectorConstIterator const & ref) const {
	return (this->_data == ref._data);
}

template <class T>
bool	ft::vectorConstIterator<T>::operator!=(vectorConstIterator const & ref) const {
	return (!(this->_data == ref._data));
}
