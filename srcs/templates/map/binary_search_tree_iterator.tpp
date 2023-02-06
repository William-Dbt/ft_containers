template <class Key, class T>
ft::bst_iterator<Key, T>::bst_iterator() : _data(NULL), _parent(NULL) {}

template <class Key, class T>
ft::bst_iterator<Key, T>::bst_iterator(node_pointer data, node_pointer parent) : _data(data), _parent(parent) {}

template <class Key, class T>
ft::bst_iterator<Key, T>::bst_iterator(const bst_iterator& ref) : _data(ref._data), _parent(ref._parent) {}

template <class Key, class T>
ft::bst_iterator<Key, T>::~bst_iterator() {}

template <class Key, class T>
ft::bst_iterator<Key, T>&	ft::bst_iterator<Key, T>::operator=(const bst_iterator& ref) {
	if (this != &ref) {
		this->_data = ref._data;
		this->_parent = ref._parent;
	}
	return *this;
}

template <class Key, class T>
ft::bst_iterator<Key, T>&	ft::bst_iterator<Key, T>::operator++() {
	if (this->_data != NULL) {
		this->_parent = this->_data;
		if (this->_data->right != NULL) { // Check if greater value exist
			this->_data = this->_data->right;
			while (this->_data && this->_data->left)
				this->_data = this->_data->left;
		}
		else { // If no greater value exist, go to the previous tree axe or just the parent
			while (this->_data->parent && this->_data->parent->right == this->_data) // The condition can be false because my operator compare the ptrs and not the values
				this->_data = this->_data->parent;

			this->_data = this->_data->parent;
		}
	}
	return *this;
}

template <class Key, class T>
ft::bst_iterator<Key, T>	ft::bst_iterator<Key, T>::operator++(int) {
	bst_iterator	tmp(this->_data, this->_parent);

	operator++();
	return tmp;
}

// The STL container come back to end() ptr when iterator is NULL (start of the tree)
// Same as operator++ but in reverse
template <class Key, class T>
ft::bst_iterator<Key, T>&	ft::bst_iterator<Key, T>::operator--() {
	if (this->_data != NULL) {
		this->_parent = this->_data;
		if (this->_data->left != NULL) {
			this->_data = this->_data->left;
			while (this->_data && this->_data->right)
				this->_data = this->_data->right;
		}
		else {
			while (this->_data->parent && this->_data->parent->left == this->_data)
				this->_data = this->_data->parent;

			this->_data = this->_data->parent;
		}
	}
	else
		this->_data = this->_parent;

	return *this;
}

template <class Key, class T>
ft::bst_iterator<Key, T>	ft::bst_iterator<Key, T>::operator--(int) {
	bst_iterator	tmp(this->_data, this->_parent);

	operator--();
	return tmp;
}

template <class Key, class T>
typename ft::bst_iterator<Key, T>::reference	ft::bst_iterator<Key, T>::operator*() const {
	return (this->_data->data);
}

template <class Key, class T>
typename ft::bst_iterator<Key, T>::pointer	ft::bst_iterator<Key, T>::operator->() const {
	return (&this->_data->data);
}

template <class Key, class T>
bool	ft::bst_iterator<Key, T>::operator==(bst_iterator<Key, T> const & ref) {
	if (this->_data == ref._data && this->_parent == ref._parent)
		return true;

	return false;
}

template <class Key, class T>
bool	ft::bst_iterator<Key, T>::operator!=(bst_iterator<Key, T> const & ref) {
	if (this->_data != ref._data && this->_parent != ref._parent)
		return true;

	return false;
}

template <class Key, class T>
template <class InputIt>
bool	ft::bst_iterator<Key, T>::operator==(InputIt const & ref) {
	return (this->_data == ref._data);
}

template <class Key, class T>
template <class InputIt>
bool	ft::bst_iterator<Key, T>::operator!=(InputIt const & ref) {
	return (this->_data != ref._data);
}

/* ------------------------------------------------------------ */
// Const Iterator Side
/* ------------------------------------------------------------ */

template <class Key, class T>
ft::const_bst_iterator<Key, T>::const_bst_iterator() : _data(NULL), _parent(NULL) {}

template <class Key, class T>
ft::const_bst_iterator<Key, T>::const_bst_iterator(node_pointer data, node_pointer parent) : _data(data), _parent(parent) {}

template <class Key, class T>
ft::const_bst_iterator<Key, T>::const_bst_iterator(const const_bst_iterator& ref) : _data(ref._data), _parent(ref._parent) {}

template <class Key, class T>
template <class InputIt>
ft::const_bst_iterator<Key, T>::const_bst_iterator(const InputIt& ref) : _data(ref._data), _parent(ref._parent) {}

template <class Key, class T>
ft::const_bst_iterator<Key, T>::~const_bst_iterator() {}

template <class Key, class T>
ft::const_bst_iterator<Key, T>&	ft::const_bst_iterator<Key, T>::operator=(const const_bst_iterator& ref) {
	if (this != &ref) {
		this->_data = ref._data;
		this->_parent = ref._parent;
	}
	return *this;
}

template <class Key, class T>
template <class InputIt>
ft::const_bst_iterator<Key, T>&	ft::const_bst_iterator<Key, T>::operator=(const InputIt& ref) {
	if (this != &ref) {
		this->_data = ref._data;
		this->_parent = ref._parent;
	}
	return *this;
}

template <class Key, class T>
ft::const_bst_iterator<Key, T>&	ft::const_bst_iterator<Key, T>::operator++() {
	if (this->_data != NULL) {
		this->_parent = this->_data;
		if (this->_data->right != NULL) { // Check if greater value exist
			this->_data = this->_data->right;
			while (this->_data && this->_data->left)
				this->_data = this->_data->left;
		}
		else { // If no greater value exist, go to the previous tree axe or just the parent
			while (this->_data->parent && this->_data->parent->right == this->_data) // The condition can be false because my operator compare the ptrs and not the values
				this->_data = this->_data->parent;

			this->_data = this->_data->parent;
		}
	}
	return *this;
}

template <class Key, class T>
ft::const_bst_iterator<Key, T>	ft::const_bst_iterator<Key, T>::operator++(int) {
	const_bst_iterator	tmp(this->_data, this->_parent);

	operator++();
	return tmp;
}

// The STL container come back to end() ptr when iterator is NULL (start of the tree)
// Same as operator++ but in reverse
template <class Key, class T>
ft::const_bst_iterator<Key, T>&	ft::const_bst_iterator<Key, T>::operator--() {
	if (this->_data != NULL) {
		this->_parent = this->_data;
		if (this->_data->left != NULL) {
			this->_data = this->_data->left;
			while (this->_data && this->_data->right)
				this->_data = this->_data->right;
		}
		else {
			while (this->_data->parent && this->_data->parent->left == this->_data)
				this->_data = this->_data->parent;

			this->_data = this->_data->parent;
		}
	}
	else
		this->_data = this->_parent;

	return *this;
}

template <class Key, class T>
ft::const_bst_iterator<Key, T>	ft::const_bst_iterator<Key, T>::operator--(int) {
	const_bst_iterator	tmp(this->_data, this->_parent);

	operator--();
	return tmp;
}

template <class Key, class T>
typename ft::const_bst_iterator<Key, T>::reference	ft::const_bst_iterator<Key, T>::operator*() const {
	return (this->_data->data);
}

template <class Key, class T>
typename ft::const_bst_iterator<Key, T>::pointer	ft::const_bst_iterator<Key, T>::operator->() const {
	return (&this->_data->data);
}

template <class Key, class T>
bool	ft::const_bst_iterator<Key, T>::operator==(const_bst_iterator<Key, T> const & ref) {
	if (this->_data == ref._data && this->_parent == ref._parent)
		return true;

	return false;
}

template <class Key, class T>
bool	ft::const_bst_iterator<Key, T>::operator!=(const_bst_iterator<Key, T> const & ref) {
	if (this->_data != ref._data && this->_parent != ref._parent)
		return true;

	return false;
}

template <class Key, class T>
template <class InputIt>
bool	ft::const_bst_iterator<Key, T>::operator==(InputIt const & ref) {
	return (this->_data == ref._data);
}

template <class Key, class T>
template <class InputIt>
bool	ft::const_bst_iterator<Key, T>::operator!=(InputIt const & ref) {
	return (this->_data != ref._data);
}
