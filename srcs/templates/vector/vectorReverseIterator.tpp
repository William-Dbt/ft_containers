template <class T>
ft::vectorReverseIterator<T>::vectorReverseIterator() : _data(NULL) {}

template <class T>
ft::vectorReverseIterator<T>::vectorReverseIterator(pointer data) : _data(data) {}

template <class T>
ft::vectorReverseIterator<T>::vectorReverseIterator(vectorReverseIterator const & ref) {
	this->_data = ref._data;
}

template <class T>
ft::vectorReverseIterator<T>::~vectorReverseIterator() {}

template <class T>
ft::vectorReverseIterator<T>::operator vectorReverseIterator<const T>() const
{
	return vectorReverseIterator<const T>(this->_data);
}

template <class T>
ft::vectorReverseIterator<T>&	ft::vectorReverseIterator<T>::operator=(vectorReverseIterator const & ref) {
	if (this != &ref)
		this->_data = ref._data;

	return *this;
}

template <class T>
ft::vectorReverseIterator<T>&	ft::vectorReverseIterator<T>::operator++() {
	this->_data--;
	return *this;
}

template <class T>
ft::vectorReverseIterator<T>	ft::vectorReverseIterator<T>::operator++(int) {
	vectorReverseIterator	tmp(*this);

	operator++();
	return tmp;
}

template <class T>
ft::vectorReverseIterator<T>&	ft::vectorReverseIterator<T>::operator--() {
	this->_data++;
	return *this;
}

template <class T>
ft::vectorReverseIterator<T>	ft::vectorReverseIterator<T>::operator--(int) {
	vectorReverseIterator	tmp(*this);

	operator--();
	return tmp;
}

template <class T>
typename ft::vectorReverseIterator<T>::reference	ft::vectorReverseIterator<T>::operator*() {
	return (*this->_data);
}

template <class T>
typename ft::vectorReverseIterator<T>::const_reference	ft::vectorReverseIterator<T>::operator*() const {
	return (*this->_data);
}

template <class T>
typename ft::vectorReverseIterator<T>::pointer	ft::vectorReverseIterator<T>::operator->() {
	return (&this->_data);
}

template <class T>
typename ft::vectorReverseIterator<T>::pointer	ft::vectorReverseIterator<T>::operator->() const {
	return (&this->_data);
}

template <class T>
typename ft::vectorReverseIterator<T>::reference	ft::vectorReverseIterator<T>::operator[](distance d) {
	return (*(this->_data - d));
}

template <class T>
typename ft::vectorReverseIterator<T>::const_reference	ft::vectorReverseIterator<T>::operator[](distance d) const {
	return (*(this->_data - d));
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator>(vectorReverseIterator const & ref) const {
	return (this->_data < ref._data);
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator<(vectorReverseIterator const & ref) const {
	return (this->_data > ref._data);
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator>=(vectorReverseIterator const & ref) const {
	return (this->_data <= ref._data);
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator<=(vectorReverseIterator const & ref) const {
	return (this->_data >= ref._data);
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator==(vectorReverseIterator const & ref) const {
	return (this->_data == ref._data);
}

template <class T>
bool	ft::vectorReverseIterator<T>::operator!=(vectorReverseIterator const & ref) const {
		return (!(this->_data == ref._data));
}
