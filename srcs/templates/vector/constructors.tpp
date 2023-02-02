template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) : _datas(NULL), _alloc(alloc),
														_size(0), _capacity(0) {}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& value, const allocator_type& alloc) :
							_alloc(alloc), _size(n), _capacity(n)
{
	pointer	tmp;

	this->_datas = this->_alloc.allocate(this->_capacity);
	tmp = this->_datas;
	for (size_type i = 0; i < n; i++)
		this->_alloc.construct(tmp++, value);
}

template <class T, class Alloc>
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

template <class T, class Alloc>
template <class InputIt>
ft::vector<T, Alloc>::vector(InputIt first, InputIt last, const allocator_type& alloc,
							typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*) :
							_alloc(alloc)
{
	this->_size = ft::distance(first, last);
	this->_capacity = this->_size;
	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; first != last; i++, first++)
		this->_alloc.construct(&this->_datas[i], *first);
}

template <class T, class Alloc>
ft::vector<T, Alloc>::~vector() {
	pointer	tmp;

	tmp = this->_datas;
	for (size_type i = 0; i < this->_size; i++)
		this->_alloc.destroy(tmp++);

	this->_alloc.deallocate(this->_datas, this->_capacity);
}

template <class T, class Alloc>
ft::vector<T, Alloc>&	ft::vector<T, Alloc>::operator=(const vector& x) {
	if (this != &x) {
		this->~vector();
		new (this) vector(x);
	}
	return (*this);
}
