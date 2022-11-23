template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : _datas(NULL), _alloc(alloc),
														_size(0), _capacity(0) {}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) :
							_alloc(alloc), _size(n), _capacity(n * 2)
{
	pointer	tmp;

	this->_datas = this->_alloc.allocate(this->_capacity);
	tmp = this->_datas;
	for (size_type i = 0; i < n; i++)
		this->_alloc.construct(tmp++, value);
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const vector& other) {
	pointer	tmp;

	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_alloc = Alloc();
	this->_datas = this->_alloc.allocate(this->_capacity);
	tmp = this->_datas;
	for (size_type i = 0; i < this->_size; i++)
		this->_alloc.construct(tmp++, other[i]);
}

template <typename T, class Alloc>
template <class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc) :
							_alloc(alloc)
{
	pointer			tmp;
	InputIterator	it;

	this->_size = std::distance(first, last);
	this->_capacity = this->_size * 2;
	this->_datas = this->_alloc.allocate(this->_capacity);
	tmp = this->_datas;
	for (it = first; it != last; it++)
		this->_alloc.construct(tmp++, *it);
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::~vector() {
	pointer	tmp;

	tmp = this->_datas;
	for (size_type i = 0; i < this->_size; i++)
		this->_alloc.destroy(tmp++);

	this->_alloc.deallocate(this->_datas, this->_capacity);
}
