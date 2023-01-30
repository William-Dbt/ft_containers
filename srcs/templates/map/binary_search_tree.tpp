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

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_leftRotate(node_pointer x) {
	node_pointer	y = x->right;
	node_pointer	beta = y->left;

	y->left = x;
	x->parent = y;

	x->right = beta;
	beta->parent = x;

	x->height = maxHeight(this->getNodeHeight(x->left), this->getNodeHeight(x->right)) + 1;
	y->height = maxHeight(this->getNodeHeight(y->left), this->getNodeHeight(y->right)) + 1;
	return y;


// 	node_pointer y = x->right;
// 	node_pointer T2 = y->left;

// 	y->left = x;
// 	x->right = T2;
// 	x->height = maxHeight(getNodeHeight(x->left),
// 		  getNodeHeight(x->right)) +
// 		1;
//   y->height = maxHeight(getNodeHeight(y->left),
// 		  getNodeHeight(y->right)) +
// 		1;
//   return y;

	// node_pointer	y = x->right;

	// if (y->left != NULL)
	// 	y->left->parent = x;

	// if (x->parent == NULL) {
	// 	this->_root = y;
	// 	this->_root->parent = NULL;
	// 	x->parent = this->_root;
	// }
	// else if (x->data.first < x->parent->data.first)
	// 	x->parent->left = y;
	// else
	// 	x->parent->right = y;

	// // y->left = x;
	// x->parent = y;
	// x->height = maxHeight(this->getNodeHeight(x->left), this->getNodeHeight(x->right)) + 1;
	// y->height = maxHeight(this->getNodeHeight(y->left), this->getNodeHeight(y->right)) + 1;
	// return y;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_rightRotate(node_pointer y) {
	// node_pointer	x = y->left;
	// node_pointer	beta = x->right;

	// x->right = y;
	// y->parent = x;

	// y->left = beta;
	// beta->parent = y;

	// x->height = maxHeight(this->getNodeHeight(x->left), this->getNodeHeight(x->right)) + 1;
	// y->height = maxHeight(this->getNodeHeight(y->left), this->getNodeHeight(y->right)) + 1;
	// return x;

// 	node_pointer	x = y->left;
// 	node_pointer	T2 = x->right;

// 	x->right = y;
// 	y->left = T2;
// 	y->height = maxHeight(getNodeHeight(y->left),
// 		  getNodeHeight(y->right)) +
// 		1;
//   x->height = maxHeight(getNodeHeight(x->left),
// 		  getNodeHeight(x->right)) +
// 		1;
//   return x;

	// node_pointer	x = y->left;

	// if (x->right != NULL)
	// 	x->right->parent = y;

	// if (y->parent == NULL) {
	// 	this->_root = x;
	// 	this->_root->parent = NULL;
	// 	y->parent = this->_root;
	// }
	// else if (y->data.first > y->parent->data.first)
	// 	y->parent->right = x;
	// else
	// 	y->parent->left = x;

	// x->right = y;
	// // y->parent = x;
	// x->height = maxHeight(this->getNodeHeight(x->left), this->getNodeHeight(x->right)) + 1;
	// y->height = maxHeight(this->getNodeHeight(y->left), this->getNodeHeight(y->right)) + 1;
	// return x;
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
	this->_root = this->_insertNode(NULL, this->_root, data);
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_insertNode(node_pointer parent, node_pointer node, const value_type& data) {
	int	balanceFactor;

	if (node == NULL) {
		node = this->_createNode(data);
		if (parent != NULL) {
			if (data.first < parent->data.first)
				parent->left = node;
			else
				parent->right = node;
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
	if (balanceFactor < -1) {
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
	this->_eraseNode(this->_root, data);
}

template <class T>
void	ft::BSTree<T>::_eraseNode(node_pointer node, const value_type& data) {
	if (this->_root == NULL)
		return ;

	if (this->_root->data.first == data.first)
		this->_removeRootNode();
	else {
		if (node->left != NULL && data < node->data)
			node->left->data.first == data.first ? this->_eraseNode(node, node->left, true) : this->_eraseNode(node->left, data);
		else if (node->right != NULL && data.first > node->data.first)
			node->right->data.first == data.first ? this->_eraseNode(node, node->right, false) : this->_eraseNode(node->right, data);
	}
}

template <class T>
void	ft::BSTree<T>::_eraseNode(node_pointer parent, node_pointer node, bool isLeft) {
	value_type	smallestKeyRightTree;
	// int			balanceFactor;

	if (this->_root == NULL)
		return ;

	if (node->left == NULL && node->right == NULL) { // Case 0: 0 children
		isLeft == true ? parent->left = NULL : parent->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left == NULL && node->right != NULL) { // Case 1: 1 child
		isLeft == true ? parent->left = node->right : parent->right = node->right;
		node->right->parent = parent;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left != NULL && node->right == NULL) {
		isLeft == true ? parent->left = node->left : parent->right = node->left;
		node->left->parent = parent;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else { // Case 2: 2 children
		smallestKeyRightTree = this->_findSmallest(node->right)->data;
		this->_eraseNode(node, smallestKeyRightTree);
		node->data = smallestKeyRightTree;
	}

	/* while (parent != NULL) {
		node->height = maxHeight(this->_getNodeHeight(node->left), this->_getNodeHeight(node->right)) + 1;
		balanceFactor = this->getBalanceFactor(node);
		if (balanceFactor > 1) {
			if (this->getBalanceFactor(node->left) >= 0)
				return this->_rightRotate(node);
			else {
				node->left = this->_leftRotate(node->left);
				return this->_rightRotate(node);
			}
		}
		if (balanceFactor < -1) {
			if (this->getBalanceFactor(node->right) <= 0)
				return this->_leftRotate(node);
			else {
				node->right = this->_rightRotate(node->right);
				return this->_leftRotate(node);
			}
		}
	} */
}

template <class T>
void	ft::BSTree<T>::_removeRootNode() {
	node_pointer	node;
	value_type		smallestKeyRightTree;

	if (this->_root == NULL)
		return ;

	node = this->_root;
	if (this->_root->left == NULL && this->_root->right == NULL) { // Case 0: 0 children
		this->_root = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (this->_root->left == NULL && this->_root->right != NULL) { // Case 1: 1 child
		this->_root = this->_root->right;
		this->_root->parent = NULL;
		// node->right->parent = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (this->_root->left != NULL && this->_root->right == NULL) {
		this->_root = this->_root->left;
		this->_root->parent = NULL;
		// node->left->parent = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else { // Case 2: 2 children
		smallestKeyRightTree = this->_findSmallest(this->_root->right)->data;
		this->_eraseNode(this->_root, smallestKeyRightTree);
		this->_root->data = smallestKeyRightTree;
	}
}

/* template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::eraseNode(const value_type& data) {
	this->_root = this->_eraseNode(this->_root, data);
	return this->_root;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_eraseNode(node_pointer node, const value_type& data) {
	int				balanceFactor;
	node_pointer	tmp;

	if (node == NULL)
		return NULL;

	if (data.first < node->data.first)
		node->left = _eraseNode(node->left, data);
	else if (data.first > node->data.first)
		node->right = _eraseNode(node->right, data);
	else {
		// Check if the node is a leaf or not
		if (node->left == NULL || node->right == NULL) {
			// Get the child of the leaf (if exists)
			if (node->left != NULL)
				tmp = node->left;
			else
				tmp = node->right;

			// If leaf has no child
			if (tmp == NULL) {
				if (node->data.first < node->parent->data.first)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
			}
			else {
				if (node->data.first < node->parent->data.first) {
					node->parent->left = tmp;
					tmp->parent = node->parent;
				}
				else {
					node->parent->right = tmp;
					tmp->parent = node->parent;
				}
			}
			this->_alloc.destroy(node);
			this->_alloc.deallocate(node, 1);
		}
		else {
			tmp = this->_findSmallest(node->right);
			node->data = tmp->data;
			node->right = this->_eraseNode(node->right, tmp->data);
		}
	}
	if (node == NULL)
		return NULL;

	node->height = maxHeight(this->_getNodeHeight(node->left), this->_getNodeHeight(node->right)) + 1;
	balanceFactor = this->getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (this->getBalanceFactor(node->left) >= 0)
			return this->_rightRotate(node);
		else {
			node->left = this->_leftRotate(node->left);
			return this->_rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (this->getBalanceFactor(node->right) <= 0)
			return this->_leftRotate(node);
		else {
			node->right = this->_rightRotate(node->right);
			return this->_leftRotate(node);
		}
	}
	return node;
} */

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
	node_pointer	tmp;

	tmp = this->_root;
	this->_root = ref._root;
	ref._root = tmp;
}
