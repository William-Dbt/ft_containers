template <class Key, class T, class Compare, class Alloc>
ft::pair<iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type& value) {
	this->_tree.addLeaf(value);
}
