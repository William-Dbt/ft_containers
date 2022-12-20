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
	if (n == this->_size || n < 0)
		return ;

	if (n > this->_capacity)
		this->changeCapacity(this->_capacity + (n - this->_capacity) * 2);

	if (n > this->_size) {
		for (size_type i = this->_size; i < n; i++) {
			if (val != value_type())
				this->_alloc.construct(&this->_datas[i], val);
			else
				this->_alloc.construct(&this->_datas[i], value_type());
		}
	}
	else
		for (size_type i = n; i < this->_size; i++)
			this->_alloc.destroy(&this->_datas[i]);

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

template <class T, class Alloc>
void	ft::vector<T, Alloc>::reserve(size_type n) {
	if (n > this->max_size())
		throw std::length_error("capacity exceed max_size limits");

	if (n > this->_capacity)
		this->changeCapacity(n);
}

/* C++11 function
template <class T, class Alloc>
void	ft::vector<T, Alloc>::shrink_to_fit() {
	this->changeCapacity(this->_size);
} */
