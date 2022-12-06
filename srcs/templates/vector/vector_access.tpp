// For operator[], accessing an index out of bounds refers to undefined behavior
template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference&	ft::vector<T, Alloc>::operator[](size_type n) {
	return this->_datas[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference&	ft::vector<T, Alloc>::operator[](size_type n) const {
	return this->_datas[n];
}
