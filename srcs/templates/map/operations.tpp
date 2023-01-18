template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::find(const key_type& k) {
	ft::pair<Key, T>	buffer(k, mapped_type());

	if (this->_tree.findNode(buffer) == NULL)
		return (this->end());

	return (iterator(this->_tree.findNode(buffer), NULL));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::find(const key_type& k) const {
	ft::pair<Key, T>	buffer(k, mapped_type());

	if (this->_tree.findNode(buffer) == NULL)
		return (this->end());

	return (const_iterator(this->_tree.findNode(buffer), NULL));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::count(const key_type& k) const {
	if (this->_tree.findNode(ft::pair<Key, T>(k, mapped_type())) == NULL)
		return 0;

	return 1;
}
