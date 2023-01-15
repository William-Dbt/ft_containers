// Todo
template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type& value) {
	this->_tree.addLeaf(value);

	return (ft::make_pair(iterator(NULL, NULL), true));
}
