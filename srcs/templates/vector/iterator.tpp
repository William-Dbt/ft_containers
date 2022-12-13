template <class T>
ft::vectorIterator<T>::vectorIterator() : _data(NULL) {}

template <class T>
ft::vectorIterator<T>::vectorIterator(pointer data) : _data(data) {}

template <class T>
ft::vectorIterator<T>::vectorIterator(vectorIterator & ref) {
	if (this != &ref)
		this->_data = ref._data;

	return (this);
}
