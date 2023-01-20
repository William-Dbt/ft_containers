template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::allocator_type	ft::map<Key, T, Compare, Alloc>::get_allocator() const {
	return this->_alloc;
}
