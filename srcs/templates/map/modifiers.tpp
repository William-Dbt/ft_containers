template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type& value) {
	if (this->_tree.findNode(value) == NULL) {
		this->_tree.insertNode(value);
		return (ft::make_pair(iterator(this->_tree.findNode(value), NULL), true));
	}
	return (ft::make_pair(iterator(this->_tree.findNode(value), NULL), false));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::insert(iterator pos, const value_type& value) {
	(void)pos;

	if (this->_tree.findNode(value) != NULL)
		return (iterator(this->_tree.findNode(value), NULL));

	this->insert(value);
	return (iterator(this->_tree.findNode(value), NULL));
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIt>
void	ft::map<Key, T, Compare, Alloc>::insert(InputIt first, InputIt last) {
	for (; first != last; first++)
		this->insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(iterator position) {
	this->_tree.eraseNode(*position);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::erase(const key_type& k) {
	iterator	it = find(k);

	if (it != end()) {
		erase(it);
		return 1;
	}
	return 0;
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
	while (first != last)
		erase(first++);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::swap(map& x) {
	this->_tree.swap(x._tree);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::clear() {
	this->_tree.deleteTree();
}
