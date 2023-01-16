template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::begin() {
	return (iterator(this->_tree.findSmallest(), NULL));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::begin() const {
	return (const_iterator(this->_tree.findSmallest(), NULL));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::end() {
	return (iterator(NULL, this->_tree.findGreatest()));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::end() const {
	return (const_iterator(NULL, this->_tree.findGreatest()));
}

// TODO
// template <class Key, class T, class Compare, class Alloc>
// typename ft::map<Key, T, Compare, Alloc>::reverse_iterator	ft::map<Key, T, Compare, Alloc>::rbegin() {
// 	return (reverse_iterator(this->_tree.findGreatest()));
// }

// template <class Key, class T, class Compare, class Alloc>
// typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator	ft::map<Key, T, Compare, Alloc>::rbegin() const {
// 	return (const_reverse_iterator(this->_tree.findGreatest()));
// }

// template <class Key, class T, class Compare, class Alloc>
// typename ft::map<Key, T, Compare, Alloc>::reverse_iterator	ft::map<Key, T, Compare, Alloc>::rend() {
// 	return (reverse_iterator(this->_tree.findSmallest()));
// }

// template <class Key, class T, class Compare, class Alloc>
// typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator	ft::map<Key, T, Compare, Alloc>::rend() const {
// 	return (reverse_iterator(this->_tree.findSmallest()));
// }
