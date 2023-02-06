template <class Key, class T, class Compare, class Alloc>
bool	ft::map<Key, T, Compare, Alloc>::empty() const {
	if (this->_tree.size() == 0)
		return true;

	return false;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::size() const {
	return this->_tree.size();
}

// A max_size function is maded in the binary search tree part because we want to know how much node we can alloc
// A call on the std::allocator of map refers to how much pair can be created
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::max_size() const {
	return this->_tree.max_size();
}
