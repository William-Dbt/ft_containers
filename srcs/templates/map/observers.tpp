template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare	ft::map<Key, T, Compare, Alloc>::key_comp() const {
	return key_compare();
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare	ft::map<Key, T, Compare, Alloc>::value_comp() const {
	return value_compare(key_compare());
}
