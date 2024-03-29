// ------------------------------------------------------------------------------------------
// Binary Search Tree Part
// This part was done with the AVL Tree Algorithm (https://www.programiz.com/dsa/avl-tree)
// ------------------------------------------------------------------------------------------
template <class Key, class T, class Compare>
ft::BSTree<Key, T, Compare>::BSTree() : _root(NULL), _size(0) {}

template <class Key, class T, class Compare>
ft::BSTree<Key, T, Compare>::BSTree(const value_type& key) : _size(1) {
	this->_root = this->_alloc.allocate(1);
	this->_alloc.construct(this->_root, ft::Node<Key, T>(key));
}

template <class Key, class T, class Compare>
ft::BSTree<Key, T, Compare>::~BSTree() {} // The tree is deleted in the map container calling the deleteTree() function

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::printInOrder() {
	_printInOrder(this->_root);
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::_printInOrder(node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (node->left != NULL)
		_printInOrder(node->left);

	std::cout << node->data << " ";
	if (node->right != NULL)
		_printInOrder(node->right);
}

template <class Key, class T, class Compare>
int	ft::BSTree<Key, T, Compare>::_maxHeight(const int& lhs, const int& rhs) {
	if (lhs > rhs)
		return lhs;

	return rhs;
}

template <class Key, class T, class Compare>
int	ft::BSTree<Key, T, Compare>::getNodeHeight(node_pointer node) const {
	if (node == NULL)
		return 0;

	return node->height;
}

template <class Key, class T, class Compare>
int	ft::BSTree<Key, T, Compare>::getBalanceFactor(node_pointer node) const {
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
template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_leftRotate(node_pointer x) {
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

	x->height = this->_maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
	y->height = this->_maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
	return y;
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_rightRotate(node_pointer y) {
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

	y->height = this->_maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
	x->height = this->_maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
	return x;
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_rightLeftRotate(node_pointer node) {
	node->right = _rightRotate(node->right);
	return (_leftRotate(node));
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_leftRightRotate(node_pointer node) {
	node->left = _leftRotate(node->left);
	return (_rightRotate(node));
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_createNode(const value_type& data) {
	node_pointer	buffer;

	buffer = this->_alloc.allocate(1);
	this->_alloc.construct(buffer, ft::Node<Key, T>(data));
	return buffer;
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::insertNode(const value_type& data) {
	this->_root = this->_insertNode(NULL, this->_root, data);
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_insertNode(node_pointer parent, node_pointer node, const value_type& data) {
	int	balanceFactor;

	if (node == NULL) {
		node = this->_createNode(data);
		if (parent != NULL) {
			if (this->_comp(data.first, parent->data.first))
				parent->left = node;
			else
				parent->right = node;

			node->parent = parent;
		}
		this->_size++;
		return node;
	}
	if (this->_comp(data.first, node->data.first))
		node->left = this->_insertNode(node, node->left, data);
	else if (this->_comp(node->data.first, data.first))
		node->right = this->_insertNode(node, node->right, data);
	else
		return node;

	node->height = this->_maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
	balanceFactor = this->getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (this->_comp(data.first, node->left->data.first))
			return this->_rightRotate(node);
		else if (this->_comp(node->left->data.first, data.first))
			return this->_leftRightRotate(node);
	}
	else if (balanceFactor < -1) {
		if (this->_comp(node->right->data.first, data.first))
			return this->_leftRotate(node);
		else if (this->_comp(data.first, node->right->data.first))
			return this->_rightLeftRotate(node);
	}
	return node;
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::eraseNode(const value_type& data) {
	_eraseNode(data, this->_root);
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::_eraseNode(value_type data, node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (this->_root->data.first == data.first)
		_removeRootNode();
	else {
		if (node->left != NULL && data < node->data)
			node->left->data.first == data.first ? this->_eraseNode(node, node->left, true) : this->_eraseNode(data, node->left);
		else if (node->right != NULL && data.first > node->data.first)
			node->right->data.first == data.first ? this->_eraseNode(node, node->right, false) : this->_eraseNode(data, node->right);
	}
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::_eraseNode(node_pointer parent, node_pointer node, bool isLeft) {
	value_type	smallestDataRightTree;

	if (this->_root == NULL)
		return ;

	if (node->left == NULL && node->right == NULL) { // Case 0: 0 children
		isLeft == true ? parent->left = NULL : parent->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		node = NULL;
		this->_size--;
	}
	else if (node->left == NULL && node->right != NULL) { // Case 1: 1 child
		isLeft == true ? parent->left = node->right : parent->right = node->right;
		node->right->parent = parent;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		node = NULL;
		this->_size--;
	}
	else if (node->left != NULL && node->right == NULL) {
		isLeft == true ? parent->left = node->left : parent->right = node->left;
		node->left->parent = parent;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		node = NULL;
		this->_size--;
	}
	else { // Case 2: 2 children
		smallestDataRightTree = this->_findSmallest(node->right)->data;
		this->_eraseNode(smallestDataRightTree, node);
		node->data = smallestDataRightTree;
	}
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::_removeRootNode() {
	node_pointer	node;
	value_type		smallestDataRightTree;

	if (this->_root == NULL)
		return ;

	node = this->_root;
	if (this->_root->left == NULL && this->_root->right == NULL) { // Case 0: 0 children
		this->_root = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		this->_size--;
	}
	else if (this->_root->left == NULL && this->_root->right != NULL) { // Case 1: 1 child
		this->_root = this->_root->right;
		this->_root->parent = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		node = NULL;
		this->_size--;
	}
	else if (this->_root->left != NULL && this->_root->right == NULL) {
		this->_root = this->_root->left;
		this->_root->parent = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
		node = NULL;
		this->_size--;
	}
	else { // Case 2: 2 children
		smallestDataRightTree = this->_findSmallest(this->_root->right)->data;
		this->_eraseNode(smallestDataRightTree, this->_root);
		this->_root->data = smallestDataRightTree;
	}
}

// template <class Key, class T, class Compare>
// void	ft::BSTree<Key, T, Compare>::eraseNode(const value_type& data) {
// 	// if (this->_root == NULL)
// 	// 	return ;
// 	// std::cout << "erase: " << data << std::endl;

// 	this->_root = this->_eraseNode(this->_root, data);
// }

// template <class Key, class T, class Compare>
// typename ft::BSTree<Key, T, Compare>::node_pointer ft::BSTree<Key, T, Compare>::_eraseNode(node_pointer node, const value_type& data) {
// 	node_pointer	nodeTmp;
// 	value_type		dataTmp;
// 	bool			isChildLeft;
// 	int				balanceFactor;

// 	if (node == NULL)
// 		return NULL;
// 	else if (this->_comp(data.first, node->data.first))
// 		node->left = this->_eraseNode(node->left, data);
// 	else if (this->_comp(node->data.first, data.first))
// 		node->right = this->_eraseNode(node->right, data);
// 	else {
// 		// Check if the node is a leaf
// 		if (node->left == NULL || node->right == NULL) {
// 			// Check if it have a child
// 			if (node->left != NULL) {
// 				nodeTmp = node->left;
// 				isChildLeft = true;
// 			}
// 			else {
// 				nodeTmp = node->right;
// 				isChildLeft = false;
// 			}
// 			// Delete the node if it's a leaf
// 			if (nodeTmp == NULL) {
// 				if (node->parent != NULL) {
// 					if (this->_comp(node->data.first, node->parent->data.first))
// 						node->parent->left = NULL;
// 					else
// 						node->parent->right = NULL;
// 				}
// 				this->_alloc.destroy(node);
// 				this->_alloc.deallocate(node, 1);
// 				node = NULL;
// 				this->_size--;
// 			}
// 			else {
// 				// Delete if isn't the root
// 				if (node->parent != NULL) {
// 					if (this->_comp(node->data.first, node->parent->data.first)) {
// 						if (isChildLeft)
// 							node->parent->left = node->left;
// 						else
// 							node->parent->left = node->right;
// 					}
// 					else {
// 						if (isChildLeft)
// 							node->parent->right = node->left;
// 						else
// 							node->parent->right = node->right;
// 					}
// 					this->_alloc.destroy(node);
// 					this->_alloc.deallocate(node, 1);
// 					node = NULL;
// 					this->_size--;
// 				}
// 				else {
// 					// Check if the root has a child NULL
// 					if (node->right == NULL || node->left == NULL) {
// 						this->_alloc.destroy(node);
// 						this->_alloc.deallocate(node, 1);
// 						node = NULL;
// 						nodeTmp->parent = NULL;
// 						this->_size--;
// 						return nodeTmp;
// 					}
// 					else {
// 						nodeTmp = this->_findSmallest(node->right);
// 						dataTmp = nodeTmp->data;
// 						node->right = _eraseNode(node->right, nodeTmp->data);
// 						this->_alloc.construct(node, dataTmp);
// 						return node;
// 					}
// 				}
// 			}
// 		}
// 		else { // TODO: Use construct function of alloc
// 			nodeTmp = this->_findSmallest(node->right);
// 			node->data = nodeTmp->data;
// 			node->right = _eraseNode(node->right, nodeTmp->data);
// 		}
// 	}
// 	if (node == NULL)
// 		return node;

// 	node->height = this->_maxHeight(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
// 	balanceFactor = this->getBalanceFactor(node);
// 	if (balanceFactor > 1) {
// 		if (this->_comp(data.first, node->left->data.first))
// 			return this->_rightRotate(node);
// 		else if (!this->_comp(data.first, node->left->data.first)) {
// 			node->left = this->_leftRotate(node->left);
// 			return this->_rightRotate(node);
// 		}
// 	}
// 	else if (balanceFactor < -1) {
// 		if (!this->_comp(data.first, node->right->data.first))
// 			return this->_leftRotate(node);
// 		else if (this->_comp(data.first, node->right->data.first)) {
// 			node->right = this->_rightRotate(node->right);
// 			return this->_leftRotate(node);
// 		}
// 	}
// 	return node;
// }

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::findSmallest() const {
	return (this->_findSmallest(this->_root));
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_findSmallest(node_pointer node) const {
	if (this->_root == NULL || node == NULL)
		return NULL;

	while (node && node->left != NULL)
		node = node->left;

	return node;
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::findGreatest() const {
	return (this->_findGreatest(this->_root));
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::_findGreatest(node_pointer node) const {
	if (this->_root == NULL || node == NULL)
		return NULL;

	while (node && node->right != NULL)
		node = node->right;

	return node;
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::node_pointer	ft::BSTree<Key, T, Compare>::findNode(const value_type& data) const {
	node_pointer	node = this->_root;

	if (this->_root == NULL)
		return NULL;

	while (node && node->data.first != data.first) {
		if (this->_comp(data.first, node->data.first))
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::deleteTree() {
	if (this->_root == NULL)
		return ;

	this->_removeSubTree(this->_root->left);
	this->_removeSubTree(this->_root->right);
	this->_alloc.destroy(this->_root);
	this->_alloc.deallocate(this->_root, 1);
	this->_root = NULL;
	this->_size = 0;
}

// This function refers to the printInOrder function, if we delete the smaller to the greater
// It's sure that we'll not remove a node that we need to to go up in the tree
template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::_removeSubTree(node_pointer node) {
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

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::size_type	ft::BSTree<Key, T, Compare>::max_size() const {
	return this->_alloc.max_size();
}

template <class Key, class T, class Compare>
typename ft::BSTree<Key, T, Compare>::size_type	ft::BSTree<Key, T, Compare>::size() const {
	return this->_size;
}

template <class Key, class T, class Compare>
void	ft::BSTree<Key, T, Compare>::swap(BSTree& ref) {
	node_pointer	rootTmp;
	size_type		sizeTmp;
	node_alloc		allocTmp;
	key_compare		compTmp;

	rootTmp = this->_root;
	this->_root = ref._root;
	ref._root = rootTmp;

	sizeTmp = this->_size;
	this->_size = ref._size;
	ref._size = sizeTmp;

	allocTmp = this->_alloc;
	this->_alloc = ref._alloc;
	ref._alloc = allocTmp;

	compTmp = this->_comp;
	this->_comp = ref._comp;
	ref._comp = compTmp;
}
