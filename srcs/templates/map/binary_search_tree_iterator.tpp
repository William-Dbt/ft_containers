template <class T>
ft::bst_iterator<T>::bst_iterator() : _data(NULL) {}

template <class T>
ft::bst_iterator<T>::bst_iterator(node_pointer data, node_pointer parent) : _data(data), _parent(parent) {}

template <class T>
ft::bst_iterator<T>::bst_iterator(const bst_iterator& ref) : _data(ref._data) {}

template <class T>
ft::bst_iterator<T>::~bst_iterator() {}

template <class T>
ft::bst_iterator<T>::operator bst_iterator<const T>() const {
	return bst_iterator<const T>(this->_data, this->_parent);
}

template <class T>
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator=(const bst_iterator& ref) {
	if (this != &ref) {
		this->_data = ref._data;
		this->_parent = ref._parent;
	}
	return *this;
}

template <class T>
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator++() {
	if (this->_data != NULL) {
		this->_parent = this->_data;
		if (this->_data->right != NULL) { // Check if greater value exist
			this->_data = this->_data->right;
			while (this->_data && this->_data->left)
				this->_data = this->_data->left;
		}
		else { // If no greater value exist, go to the previous tree axe or just the parent
			while (this->_data->parent && this->_data->parent->right == this->_data) // The condition is false because my operator copare the ptrs and not the values
				this->_data = this->_data->parent;

			this->_data = this->_data->parent;
		}
	}
	return *this;
}

template <class T>
ft::bst_iterator<T>	ft::bst_iterator<T>::operator++(int) {
	bst_iterator	tmp(this->_data, this->_parent);

	operator++();
	return tmp;
}

// Same as operator++ but in reverse
template <class T>
ft::bst_iterator<T>&	ft::bst_iterator<T>::operator--() {
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

template <class T>
ft::bst_iterator<T>	ft::bst_iterator<T>::operator--(int) {
	bst_iterator	tmp(this->_data, this->_parent);

	operator--();
	return tmp;
}

template <class T>
typename ft::bst_iterator<T>::reference	ft::bst_iterator<T>::operator*() const {
	return (this->_data->key);
}

template <class T>
typename ft::bst_iterator<T>::pointer	ft::bst_iterator<T>::operator->() const {
	return (&this->_data->key);
}

template <class T>
bool	ft::bst_iterator<T>::operator==(bst_iterator<const T> const & ref) {
	if (this->_data == ref._data)
		return true;

	return false;
}

template <class T>
bool	ft::bst_iterator<T>::operator!=(bst_iterator<const T> const & ref) {
	if (this->_data != ref._data)
		return true;

	return false;
}
