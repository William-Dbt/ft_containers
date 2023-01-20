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

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) {
	iterator	it;

	for (it = this->begin(); it != this->end(); it++)
		if (this->key_comp()((*it).first, k) == false)
			return it;

	return it;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const {
	const_iterator	it;

	for (it = this->begin(); it != this->end(); it++)
		if (this->key_comp()((*it).first, k) == false)
			return it;

	return it;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) {
	iterator	it;

	for (it = this->begin(); it != this->end(); it++)
		if (this->key_comp()(k, (*it).first) == true)
			return ++it;

	return it;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const {
	const_iterator	it;

	for (it = this->begin(); it != this->end(); it++)
		if (this->key_comp()(k, (*it).first) == true)
			return ++it;

	return it;
}
