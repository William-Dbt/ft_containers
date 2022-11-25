template <typename T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type	ft::vector<T, Alloc>::get_allocator() const {
	return this->_alloc;
}
