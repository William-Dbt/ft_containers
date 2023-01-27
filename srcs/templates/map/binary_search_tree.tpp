// This part was done with the youtube tutorial by PaulProgramming channel

/* ########## Node Part ########## */
template <class T>
ft::node<T>::node() : key(), parent(NULL), left(NULL), right(NULL) {}

template <class T>
ft::node<T>::node(const value_type& nKey, node_pointer nParent, node_pointer nLeft, node_pointer nRight) :
				key(nKey), parent(nParent), left(nLeft), right(nRight) {}

template <class T>
ft::node<T>::node(const node & ref) {
	*this = ref;
}

template <class T>
typename ft::node<T>::node_reference	ft::node<T>::operator=(const node & ref) {
	if (this != &ref) {
		this->key = ref.key;
		this->parent = ref.parent;
		this->left = ref.left;
		this->right = ref.right;
	}
	return (*this);
}

template <class T>
ft::node<T>::~node() {}

template <class T>
bool	operator==(const ft::node<T>& lhs, const ft::node<T>& rhs) {
	if (lhs.key != rhs.key)
		return false;

	if (lhs.parent != rhs.parent)
		return false;

	if (lhs.left != rhs.left)
		return false;

	if (lhs.right != rhs.right)
		return false;

	return true;
}

/* ########## Binary Search Tree Part ########## */
template <class T>
ft::BSTree<T>::BSTree() : _root(NULL), _nbElements(0, 0) {}

template <class T>
ft::BSTree<T>::BSTree(const value_type& key) : _nbElements(0, 0) {
	this->_root = this->_alloc.allocate(1);
	this->_alloc.construct(this->_root, ft::node<T>(key));
}

template <class T>
ft::BSTree<T>::~BSTree() {
	this->_removeSubTree(this->_root);
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::_createLeaf(value_type key) {
	node_pointer	buffer;

	buffer = this->_alloc.allocate(1);
	this->_alloc.construct(buffer, ft::node<T>(key));
	return buffer;
}

template <class T>
void	ft::BSTree<T>::_balanceTree() {
	value_type		rootKey;
	value_type		greatestKey;
	value_type		smallestKey;

	if (this->_root == NULL)
		return ;

	if (this->_nbElements.first + this->_nbElements.second < 2)
		return ;

	if (this->_nbElements.first < this->_nbElements.second && (this->_nbElements.second - this->_nbElements.first) < 2)
		return ;

	if (this->_nbElements.first > this->_nbElements.second && (this->_nbElements.first - this->_nbElements.second) < 2)
		return ;

	// Move tree to one element on right
	if (this->_nbElements.first > this->_nbElements.second) {
		greatestKey = this->_findGreatest(this->_root->left)->key;
		rootKey = this->_root->key;
		this->removeNode(greatestKey);
		this->_root->key = greatestKey;
		this->addLeaf(rootKey);
	}
	else if (this->_nbElements.first < this->_nbElements.second) { // Move tree to one element on left
		smallestKey = this->_findSmallest(this->_root->right)->key;
		rootKey = this->_root->key;
		this->removeNode(smallestKey);
		this->_root->key = smallestKey;
		this->addLeaf(rootKey);
	}
}

template <class T>
void	ft::BSTree<T>::addLeaf(value_type key) {
	node_pointer	node = this->_root;
	bool			elementAdded = false;

	if (this->_root == NULL) {
		this->_root = _createLeaf(key);
		return ;
	}
	while (!elementAdded) {
		while (!elementAdded && key.first < node->key.first) {
			if (node->left != NULL) {
				node = node->left;
				continue ;
			}
			else {
				node->left = _createLeaf(key);
				node->left->parent = node;
				elementAdded = true;
			}
		}
		while (!elementAdded && key.first > node->key.first) {
			if (node->right != NULL) {
				node = node->right;
				continue ;
			}
			else {
				node->right = _createLeaf(key);
				node->right->parent = node;
				elementAdded = true;
			}
		}
		if (key.first == node->key.first)
			return ;
	}
	if (key.first < this->_root->key.first)
		_nbElements.first++;
	else if (key.first > this->_root->key.first)
		_nbElements.second++;

	_balanceTree();
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

	std::cout << node->key << " ";
	if (node->right != NULL)
		_printInOrder(node->right);
}

template <class T>
void	ft::BSTree<T>::printChildren(value_type key) {
	node_pointer	node = this->findNode(key);

	if (node == NULL)
		return ;

	std::cout << "Parent: " << key << std::endl;
	node->left == NULL ? std::cout << "lChild: NULL" << std::endl : std::cout << "lChild: " << node->left->key << std::endl;
	node->right == NULL ? std::cout << "rChild: NULL" << std::endl : std::cout << "rChild: " << node->right->key << std::endl;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(value_type key) const {
	node_pointer	node = this->_root;

	if (node == NULL)
		return NULL;

	while (node && node->key.first != key.first) {
		if (key.first < node->key.first)
			node = node->left;
		else if (key.first > node->key.first)
			node = node->right;
	}
	return node;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::getRoot() const {
	return this->_root;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findSmallest() const {
	return (_findSmallest(this->_root));
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
	return (_findGreatest(this->_root));
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
void	ft::BSTree<T>::removeNode(value_type key) {
	_removeNode(key, this->_root);
}

template <class T>
void	ft::BSTree<T>::_removeNode(value_type key, node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (this->_root->key.first == key.first)
		_removeRootNode();
	else {
		if (node->left != NULL && key < node->key)
			node->left->key.first == key.first ? this->_removeNode(node, node->left, true) : this->_removeNode(key, node->left);
		else if (node->right != NULL && key.first > node->key.first)
			node->right->key.first == key.first ? this->_removeNode(node, node->right, false) : this->_removeNode(key, node->right);
	}
}

template <class T>
void	ft::BSTree<T>::_removeNode(node_pointer parent, node_pointer node, bool isLeft) {
	value_type	smallestKeyRightTree;

	if (this->_root == NULL)
		return ;

	if (node->left == NULL && node->right == NULL) { // Case 0: 0 children
		isLeft == true ? parent->left = NULL : parent->right = NULL;
		node->key.first < this->_root->key.first ? this->_nbElements.first-- : this->_nbElements.second--;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left == NULL && node->right != NULL) { // Case 1: 1 child
		isLeft == true ? parent->left = node->right : parent->right = node->right;
		node->key.first < this->_root->key.first ? this->_nbElements.first-- : this->_nbElements.second--;
		node->right->parent = parent;
		// node->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left != NULL && node->right == NULL) {
		isLeft == true ? parent->left = node->left : parent->right = node->left;
		node->key.first < this->_root->key.first ? this->_nbElements.first-- : this->_nbElements.second--;
		node->left->parent = parent;
		// node->left = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else { // Case 2: 2 children
		smallestKeyRightTree = this->_findSmallest(node->right)->key;
		this->_removeNode(smallestKeyRightTree, node);
		node->key = smallestKeyRightTree;
	}
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
		smallestKeyRightTree = this->_findSmallest(this->_root->right)->key;
		this->_removeNode(smallestKeyRightTree, this->_root);
		this->_root->key = smallestKeyRightTree;
	}
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
	this->_nbElements.first = 0;
	this->_nbElements.second = 0;
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
	node_pointer									tmp;
	ft::pair<unsigned long int, unsigned long int>	nbElementsTmp;

	tmp = this->_root;
	this->_root = ref._root;
	ref._root = tmp;

	nbElementsTmp = this->_nbElements;
	this->_nbElements = ref._nbElements;
	ref._nbElements = nbElementsTmp;
}
