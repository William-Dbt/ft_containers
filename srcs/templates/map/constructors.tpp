template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
	_comp(comp), _alloc(alloc) {}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map& ref)  : _comp(ref._comp), _alloc(ref._alloc) {
	this->insert(ref.begin(), ref.end());
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIt>
ft::map<Key, T, Compare, Alloc>::map(InputIt first, InputIt last, const key_compare& comp, const allocator_type& alloc) : 
	_comp(comp), _alloc(alloc) {
	this->insert(first, last);
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map() {
	this->_tree.deleteTree();
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>&	ft::map<Key, T, Compare, Alloc>::operator=(const map& ref) {
	if (this != &ref) {
		this->_comp = ref._comp;
		this->_alloc = ref._alloc;
		this->clear();
		this->insert(ref.begin(), ref.end());
	}
	return *this;
}
