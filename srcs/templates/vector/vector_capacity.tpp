template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::size() const {
	return this->_size;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::max_size() const {
	return this->_alloc.max_size();
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::resize(size_type n, value_type val) {
	pointer	dataTmp = this->_datas;

	if (n == this->_size || n == 0)
		return ;

	if (n > this->_capacity)
		this->changeCapacity(this->_capacity + (n - this->_capacity) * 2);

	if (n < this->_size) {
		dataTmp += n;
		for (size_type i = n; i < this->_size; i++) {
			this->_alloc.destroy(dataTmp);
			*dataTmp++ = value_type();
		}
	}
	else {
		dataTmp += this->_size;
		for (size_type i = this->_size; i < n; i++)
			this->_alloc.construct(dataTmp++, val);
	}
	this->_size = n;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::capacity() const {
	return (this->_capacity);
}

template <class T, class Alloc>
bool	ft::vector<T, Alloc>::empty() const {
	return (!this->_size);
}
