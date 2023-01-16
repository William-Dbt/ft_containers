template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type& value) {
	if (this->_tree.findNode(value) == NULL) {
		this->_tree.addLeaf(value);
		this->_size++;
		return (ft::make_pair(iterator(this->_tree.findNode(value), NULL), true));
	}
	return (ft::make_pair(iterator(this->_tree.findNode(value), NULL), false));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::insert(iterator pos, const value_type& value) {
	// iterator	it = pos;
	(void)pos;

	if (this->_tree.findNode(value) != NULL)
		return (iterator(this->_tree.findNode(value), NULL));

	this->insert(value);
	// MB TODO - Optimize adding element in tree by pos
	// if (pos == NULL)
	// 	this->insert(value);
	// else {
	// 	if (pos->key.first < value.first)
	// 		std::cout << "key <" << std::endl;
	// 	else
	// 		std::cout << "key >" << std::endl;
	// }
	return (iterator(this->_tree.findNode(value), NULL));
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIt>
void	ft::map<Key, T, Compare, Alloc>::insert(InputIt first, InputIt last) {
	for (; first != last; first++)
		this->insert(first._data->key);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(iterator position) {
	this->_tree.removeNode(position._data->key);
	this->_size--;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::erase(const key_type& k) {
	ft::pair<key_type, mapped_type>	buffer(k, mapped_type());
	iterator						it(this->_tree.findNode(buffer), NULL);

	if (it != this->end()) {
		this->erase(it);
		return 1;
	}
	// if (this->_tree.findNode(buffer) != NULL) {
		// this->_tree.removeNode(buffer);
		// this->_size--;
		// return 1;
	// }
	return 0;
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
	while (first != last) {
		this->erase(first->_data->key);
		first++;
	}
}
