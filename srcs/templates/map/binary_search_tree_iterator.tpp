template <class T>
ft::bst_iterator<T>::bst_iterator() : _data(NULL) {}

template <class T>
ft::bst_iterator<T>::bst_iterator(const bst_iterator& ref) : _data(ref._data) {}

template <class T>
ft::bst_iterator<T>::~bst_iterator() {}

template <class T>
ft::bst_iterator<T>::operator bst_iterator<const T>() const {
	return bst_iterator<const T>(this->_data);
}

template <class T>
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator=(const bst_iterator& ref) {
	if (this != &ref)
		this->_data = ref._data;

	return *this;
}

template <class T> // Todo
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator++() {
	this->_data++;
	return *this;
}

template <class T>
ft::bst_iterator<T>	ft::bst_iterator<T>::operator++(int) {
	bst_iterator	tmp(this->_data);

	operator++();
	return tmp;
}

template <class T> // Todo
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator--() {
	this->_data--;
	return *this;
}

template <class T>
ft::bst_iterator<T>	ft::bst_iterator<T>::operator--(int) {
	bst_iterator	tmp(this->_data);

	operator--();
	return tmp;
}

template <class T>
typename ft::bst_iterator<T>::reference	ft::bst_iterator<T>::operator*() {
	return (*this->_data);
}

template <class T>
typename ft::bst_iterator<T>::pointer	ft::bst_iterator<T>::operator->() {
	return (&(this->operator*()));
}

template <class T>
bool	ft::bst_iterator<T>::operator==(bst_iterator<const T> const & ref) {
	if (this->_data == ref._data)
		return true;

	return false;
}

template <class T>
bool	ft::bst_iterator<T>::operator!=(bst_iterator<const T> const & ref) {
	if (this->_data != ref._data)
		return true;

	return false;
}
