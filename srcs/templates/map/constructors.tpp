template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
	_size(0), _comp(comp), _alloc(alloc) {}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map& ref) {
	(void)ref;
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIt>
ft::map<Key, T, Compare, Alloc>::map(InputIt first, InputIt last, const key_compare& comp, const allocator_type& alloc) : 
	_comp(comp), _alloc(alloc)
{
	(void)first;
	(void)last;
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map() {
	;
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>	ft::map<Key, T, Compare, Alloc>::operator=(const map& ref) {
	(void)ref;
}
