template <typename T, class Alloc>
ft::vector<T, Alloc>::vector() : _datas(NULL), _alloc(Alloc()), _size(0), _capacity(0) {}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : _datas(NULL), _alloc(alloc),
														_size(0), _capacity(0) {}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) :
							 _alloc(alloc), _size(n), _capacity(n) {
	this->_datas = this->_alloc.allocate(2);
w	for (size_type i = 0; i < n; i++)
		this->_datas[i] = value;
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::~vector() {
	this->_alloc.deallocate(this->_datas, this->_size);
}
