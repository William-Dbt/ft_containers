template <class T>
ft::bst_iterator<T>::bst_iterator() : _data(NULL), _parent(NULL) {}

template <class T>
ft::bst_iterator<T>::bst_iterator(node_pointer data, node_pointer parent) : _data(data), _parent(parent) {}

template <class T>
ft::bst_iterator<T>::bst_iterator(const bst_iterator& ref) : _data(ref._data), _parent(ref._parent) {}

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
			while (this->_data->parent && this->_data->parent->right == this->_data) // The condition can be false because my operator compare the ptrs and not the values
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

// The STL container come back to end() ptr when iterator is NULL (start of the tree)
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
	return (this->_data->data);
}

template <class T>
typename ft::bst_iterator<T>::pointer	ft::bst_iterator<T>::operator->() const {
	return (&this->_data->data);
}

template <class T>
bool	ft::bst_iterator<T>::operator==(bst_iterator<const T> const & ref) {
	if (this->_data == ref._data && this->_parent == ref._parent)
		return true;

	return false;
}

template <class T>
bool	ft::bst_iterator<T>::operator!=(bst_iterator<const T> const & ref) {
	if (this->_data != ref._data && this->_parent != ref._parent)
		return true;

	return false;
}





/* template <typename Key, typename Value>
class Map {
private:
    struct Node {
        std::pair<const Key, Value> data;
        Node* left;
        Node* right;
    };
    Node* root_;

    // Other map implementation details

public:
    class MapIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<const Key, Value>;
        using reference = value_type&;
        using pointer = value_type*;
        using difference_type = std::ptrdiff_t;

        MapIterator(Node* node) : node_(node) {}

        reference operator*() { return node_->data; }
        pointer operator->() { return &(node_->data); }

        MapIterator& operator++() {
            if (node_->right) {
                node_ = node_->right;
                while (node_->left) {
                    node_ = node_->left;
                }
            } else {
                Node* parent = node_->parent;
                while (parent && node_ == parent->right) {
                    node_ = parent;
                    parent = parent->parent;
                }
                node_ = parent;
            }
            return *this;
        }

        MapIterator operator++(int) {
            auto copy(*this);
            ++(*this);
            return copy;
        }

        MapIterator& operator--() {
            if (node_->left) {
                node_ = node_->left;
                while (node_->right) {
                    node_ = node_->right;
                }
            } else {
                Node* parent = node_->parent;
                while (parent && node_ == parent->left) {
                    node_ = parent;
                    parent = parent->parent;
                }
                node_ = parent;
            }
            return *this;
        }

        MapIterator operator--(int) {
            auto copy(*this);
            --(*this);
            return copy;
        }

        bool operator==(const MapIterator& other) const { return node_ == other.node_; }
        bool operator!=(const MapIterator& other) const { return node_ != other.node_; }

    private:
        Node* node_;
    };

    // Other map member functions

    MapIterator begin() {
        Node* node = root_;
        while (node->left) {
            node = node->left;
        }
        return MapIterator(node);
    }

    MapIterator end() {
        return MapIterator(nullptr);
    }
}; */
