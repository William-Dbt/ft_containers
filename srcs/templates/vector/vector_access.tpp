// For operator[], accessing an index out of bounds refers to undefined behavior
template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::operator[](size_type n) {
	return this->_datas[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::operator[](size_type n) const {
	return this->_datas[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::at(size_type n) {
	if (n >= this->_size)
		throw std::out_of_range("Index out of bounds!");

	return this->_datas[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::at(size_type n) const {
	if (n >= this->_size)
		throw std::out_of_range("Index out of bounds!");

	return this->_datas[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::front() {
	return this->_datas[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::front() const{
	return this->_datas[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::back() {
	return this->_datas[this->_size - 1];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::back() const{
	return this->_datas[this->_size - 1];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::value_type*	ft::vector<T, Alloc>::data() {
	return this->_datas;
}

template <class T, class Alloc>
const typename ft::vector<T, Alloc>::value_type*	ft::vector<T, Alloc>::data() const {
	return this->_datas;
}
