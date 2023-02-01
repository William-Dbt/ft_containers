template <class T>
ft::Node<T>::Node() : data(), parent(NULL), left(NULL), right(NULL), height(1) {}

template <class T>
ft::Node<T>::Node(const value_type& vData) : data(vData), parent(NULL), left(NULL), right(NULL), height(1) {}

template <class T>
ft::Node<T>::~Node() {}

// ------------------------------------------------------------------------------------------
// Binary Search Tree Part
// This part was done with the AVL Tree Algorithm (https://www.programiz.com/dsa/avl-tree)
// ------------------------------------------------------------------------------------------
template <class T>
ft::BSTree<T>::BSTree() : _root(NULL) {}

template <class T>
ft::BSTree<T>::BSTree(const value_type& key) {
	this->_root = this->_alloc.allocate(1);
	this->_alloc.construct(this->_root, ft::Node<T>(key));
}

template <class T>
ft::BSTree<T>::~BSTree() {
	// TODO
	// Delete all the tree
	// Check the map destructor also
}

template <class T>
void	ft::BSTree<T>::printInOrder() {
	_printInOrder(this->_root);
}

template <class T>
void	ft::BSTree<T>::_printInOrder(node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (node->left != NULL)
		_printInOrder(node->left);

	std::cout << node->data << " ";
	if (node->right != NULL)
		_printInOrder(node->right);
}

static int	maxHeight(const int& lhs, const int& rhs) {
	if (lhs > rhs)
		return lhs;

	return rhs;
}

template <class T>
int	ft::BSTree<T>::getNodeHeight(node_pointer node) const {
	if (node == NULL)
		return 0;

	return node->height;
}

template <class T>
int	ft::BSTree<T>::getBalanceFactor(node_pointer node) const {
	if (node == NULL)
		return 0;

	return (getNodeHeight(node->left) - getNodeHeight(node->right));
}

/*	Original AVLTree operations given in the implementation
  Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
} */

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_leftRotate(node_pointer x) {
	node_pointer y = x->right;
	node_pointer beta = y->left;
	node_pointer parentX = x->parent;

	y->left = x;
	x->right = beta;
	if (parentX != NULL) {
		if (parentX->left == x)
			parentX->left = y;
		else
			parentX->right = y;
	}
	y->parent = x->parent;
	x->parent = y;
	if (beta != NULL)
		beta->parent = x;

	x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
	y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
	return y;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_rightRotate(node_pointer y) {
	node_pointer x = y->left;
	node_pointer beta = x->right;
	node_pointer parentY = y->parent;

	x->right = y;
	y->left = beta;
	if (parentY != NULL) {
		if (parentY->right == y)
			parentY->right = x;
		else
			parentY->left = x;
	}
	x->parent = y->parent;
	y->parent = x;
	if (beta != NULL)
		beta->parent = y;

	y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
	x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
	return x;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_createNode(const value_type& data) {
	node_pointer	buffer;

	buffer = this->_alloc.allocate(1);
	this->_alloc.construct(buffer, ft::Node<T>(data));
	return buffer;
}

template <class T>
void	ft::BSTree<T>::insertNode(const value_type& data) {
	if (this->_root == NULL)
		this->_root = this->_createNode(data);
	else
		this->_root = this->_insertNode(NULL, this->_root, data);
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_insertNode(node_pointer parent, node_pointer node, const value_type& data) {
	int	balanceFactor;

	if (node == NULL) {
		node = this->_createNode(data);
		if (parent != NULL) {
			if (data.first < parent->data.first) {
				parent->left = node;
				node->parent = parent;
			}
			else {
				parent->right = node;
				node->parent = parent;
			}
		}
		return node;
	}
	if (data.first < node->data.first)
		node->left = this->_insertNode(node, node->left, data);
	else if (data.first > node->data.first)
		node->right = this->_insertNode(node, node->right, data);
	else
		return node;

	node->height = maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
	balanceFactor = this->getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (data.first < node->left->data.first)
			return this->_rightRotate(node);
		else if (data.first > node->left->data.first) {
			node->left = this->_leftRotate(node->left);
			return this->_rightRotate(node);
		}
	}
	else if (balanceFactor < -1) {
		if (data.first > node->right->data.first)
			return this->_leftRotate(node);
		else if (data.first < node->right->data.first) {
			node->right = this->_rightRotate(node->right);
			return this->_leftRotate(node);
		}
	}
	return node;
}

template <class T>
void	ft::BSTree<T>::eraseNode(const value_type& data) {
	if (this->_root == NULL)
		return ;

	this->_root = this->_eraseNode(this->_root, data);
}

template <class T>
typename ft::BSTree<T>::node_pointer ft::BSTree<T>::_eraseNode(node_pointer node, const value_type& data) {
	node_pointer	child;
	bool			isChildLeft;
	int				balanceFactor;

	if (node == NULL)
		return NULL;
	else if (data.first < node->data.first)
		node->left = this->_eraseNode(node->left, data);
	else if (data.first > node->data.first)
		node->right = this->_eraseNode(node->right, data);
	else {
		// Check if the node is a leaf
		if (node->left == NULL || node->right == NULL) {
			// Check if it have a child
			if (node->left != NULL) {
				child = node->left;
				isChildLeft = true;
			}
			else {
				child = node->right;
				isChildLeft = false;
			}
			// Delete the node if it's a leaf
			if (child == NULL) {
				if (node->parent != NULL) {
					if (node->data.first < node->parent->data.first)
						node->parent->left = NULL;
					else
						node->parent->right = NULL;
				}
				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
				node = NULL;
			}
			else {
				if (node->parent != NULL) {
					if (node->data.first < node->parent->data.first) {
						if (isChildLeft)
							node->parent->left = node->left;
						else
							node->parent->left = node->right;
					}
					else {
						if (isChildLeft)
							node->parent->right = node->left;
						else
							node->parent->right = node->right;
					}
				}
				else {
					this->_alloc.destroy(node);
					this->_alloc.deallocate(node, 1);
					node = child;
					node->parent = NULL;
					return node;
				}
			}
		}
		else {
			child = this->_findSmallest(node->right);
			node->data = child->data;
			node->right = _eraseNode(node->right, child->data);
		}
	}
	if (node == NULL)
		return node;

	node->height = maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
	balanceFactor = this->getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (data.first < node->left->data.first)
			return this->_rightRotate(node);
		else if (data.first > node->left->data.first) {
			node->left = this->_leftRotate(node->left);
			return this->_rightRotate(node);
		}
	}
	else if (balanceFactor < -1) {
		if (data.first > node->right->data.first)
			return this->_leftRotate(node);
		else if (data.first < node->right->data.first) {
			node->right = this->_rightRotate(node->right);
			return this->_leftRotate(node);
		}
	}
	return node;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findSmallest() const {
	return (this->_findSmallest(this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_findSmallest(node_pointer node) const {
	if (this->_root == NULL || node == NULL)
		return NULL;

	while (node && node->left != NULL)
		node = node->left;

	return node;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findGreatest() const {
	return (this->_findGreatest(this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_findGreatest(node_pointer node) const {
	if (this->_root == NULL || node == NULL)
		return NULL;

	while (node && node->right != NULL)
		node = node->right;

	return node;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(const value_type& data) const {
	node_pointer	node = this->_root;

	if (this->_root == NULL)
		return NULL;

	while (node && node->data.first != data.first) {
		if (data.first < node->data.first)
			node = node->left;
		else if (data.first > node->data.first)
			node = node->right;
	}
	return node;
}

template <class T>
void	ft::BSTree<T>::deleteTree() {
	if (this->_root == NULL)
		return ;

	this->_removeSubTree(this->_root->left);
	this->_removeSubTree(this->_root->right);
	this->_alloc.destroy(this->_root);
	this->_alloc.deallocate(this->_root, 1);
	this->_root = NULL;
}

// This function refers to the printInOrder function, if we delete the smaller to the greater
// It's sure that we'll not remove a node that we need to to go up in the tree
template <class T>
void	ft::BSTree<T>::_removeSubTree(node_pointer node) {
	if (node == NULL)
		return ;

	if (node->left != NULL)
		_removeSubTree(node->left);

	if (node->right != NULL)
		_removeSubTree(node->right);
	
	this->_alloc.destroy(node);
	this->_alloc.deallocate(node, 1);
	node = NULL;
}

template <class T>
size_t	ft::BSTree<T>::max_size() const {
	return this->_alloc.max_size();
}

template <class T>
void	ft::BSTree<T>::swap(BSTree& ref) {
	node_pointer	rootTmp;
	node_alloc		allocTmp;

	rootTmp = this->_root;
	this->_root = ref._root;
	ref._root = rootTmp;

	allocTmp = this->_alloc;
	this->_alloc = ref._alloc;
	ref._alloc = allocTmp;
}
