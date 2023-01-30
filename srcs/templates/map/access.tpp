template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type&	ft::map<Key, T, Compare, Alloc>::operator[](const key_type& k) {
	ft::pair<key_type, mapped_type>	pairBuffer(k, mapped_type());

	if (this->_tree.findNode(pairBuffer) != NULL)
		return (this->_tree.findNode(pairBuffer)->data.second);

	this->insert(pairBuffer);
	return (this->_tree.findNode(pairBuffer)->data.second);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type&	ft::map<Key, T, Compare, Alloc>::at(const key_type& k) {
	ft::pair<key_type, mapped_type>	pairBuffer(k, mapped_type());

	if (this->_tree.findNode(pairBuffer) == NULL)
		throw std::out_of_range("Cannot find the given key");

	return (this->_tree.findNode(pairBuffer)->data.second);
}

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::mapped_type&	ft::map<Key, T, Compare, Alloc>::at(const key_type& k) const {
	ft::pair<key_type, mapped_type>	pairBuffer(k, mapped_type());

	if (this->_tree.findNode(pairBuffer) == NULL)
		return std::out_of_range("Cannot find the given key");

	return (this->_tree.findNode(pairBuffer)->data.second);
}
