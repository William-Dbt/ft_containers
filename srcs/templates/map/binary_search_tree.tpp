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
}

template <class T>
int	ft::BSTree<T>::_maxHeight(const int& lhs, const int& rhs)  const {
	if (lhs > rhs)
		return lhs;

	return rhs;
}

template <class T>
int	ft::BSTree<T>::_getNodeHeight(node_pointer node) const {
	if (node == NULL)
		return 0;

	return node->height;
}

template <class T>
int	ft::BSTree<T>::_getBalanceFactor(node_pointer node) const {
	if (node == NULL)
		return 0;

	return (_getNodeHeight(node->left) - _getNodeHeight(node->right));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_leftRotate(node_pointer node) {
	node_pointer	y = node->right;

	if (y->left != NULL)
		y->left->parent = node;

	if (node->parent == NULL) {
		this->_root = y;
		this->_root->parent = NULL;
		node->parent = this->_root;
	}
	else if (node->data.first < node->parent->data.first)
		node->parent->left = y;
	else
		node->parent->right = y;

	y->left = node;
	node->parent = y;
	node->height = maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
	y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right) + 1);
	return y;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_rightRotate(node_pointer node) {
	node_pointer	x = node->left;

	if (x->right != NULL)
		x->right->parent = node;

	if (node->parent == NULL) {
		this->_root = x;
		this->_root->parent = NULL;
		node->parent = this->_root;
	}
	else if (node->data.first > node->parent->data.first)
		node->parent->right = x;
	else
		node->parent->left = x;

	x->right = node;
	node->parent = x;
	x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
	node->height = maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
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
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::insert(const value_type& data) {
	this->_insert(this->_root, data);
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_insert(node_pointer node, const value_type& data) {
	int	balanceFactor;

	if (node == NULL) {
		this->_root = _createNode(data);
		return this->_root;
	}
	if (data.first < node->data.first)
		node->left = _insert(node->left, data);
	else if (data.first > node->data.first)
		node->right = _insert(node->right, data);
	else
		return node;

	node->height = maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
	balanceFactor = 
	// TODO
}

// template <class T
// typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::find(const value_type& data) const {
// 	node_pointer	node = this->_root;

// 	if (this->_root == NULL)
// 		return NULL;

// 	while (node && node->data.first != data.first) {
// 		if (data.first < node->data.first)
// 			node = node->left;
// 		else if (data.first > node->data.first)
// 			node = node->right;
// 	}
// 	return node;
// }
