#include <iostream>

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::assign(InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value,
												InputIt>::type*)
{
	size_type	i;
	size_type	newSize;

	newSize = ft::distance(first, last);
	for (i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);

	this->_size = 0;
	changeCapacity(newSize * 2);
	for (i = 0; first != last; i++, first++)
		this->_alloc.construct(&this->_datas[i], *first);

	this->_size = newSize;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::assign(size_type n, const value_type& val) {
	size_type	i;

	for (i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);
	
	this->_size = 0;
	this->changeCapacity(n * 2);
	for (i = 0; i < n; i++)
		this->_alloc.construct(&this->_datas[i], val);

	this->_size = n;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::push_back(const value_type& val) {
	if (this->_size + 1 > this->_capacity)
		this->changeCapacity(this->_capacity * 2);

	this->_datas[this->_size] = val;
	this->_size++;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::pop_back() {
	this->_alloc.destroy(&this->_datas[--this->_size]);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::insert(iterator position, const value_type& val) {
	iterator	it_end;

	(void)val;
	if (this->_size + 1 > this->_capacity)
		this->changeCapacity(this->_capacity * 2);

	for (it_end = this->end(); it_end >= position; --it_end)
		std::cout << ' ' << *it_end;

	std::cout << std::endl;
	return NULL;
}

/* template <class T, class Alloc>
void		ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val) {

}

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last) {

} */
