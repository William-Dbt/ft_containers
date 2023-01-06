/* ########## Node Part ########## */

template <class T>
ft::node<T>::node() : key(), left(NULL), right(NULL) {}

template <class T>
ft::node<T>::node(const value_type& nKey, node_pointer nLeft, node_pointer nRight) :
				key(nKey), left(nLeft), right(nRight) {}

template <class T>
ft::node<T>::node(const node & ref) {
	*this = ref;
}

template <class T>
typename ft::node<T>::node_reference	ft::node<T>::operator=(const node & ref) {
	if (this != &ref) {
		this->key = ref.key;
		this->left = ref.left;
		this->right = ref.right;
	}
	return (*this);
}

template <class T>
ft::node<T>::~node() {}

/* ########## Binary Search Tree Part ########## */
template <class T>
ft::BSTree<T>::BSTree() : _root(NULL) {}

template <class T>
ft::BSTree<T>::BSTree(const value_type& key) {
	this->_root = this->_alloc.allocate(1);
	this->_alloc.construct(this->_root, ft::node<T>(key));
}

template <class T>
ft::BSTree<T>::~BSTree() {
	if (this->_root != NULL) {
		this->_alloc.destroy(this->_root);
		this->_alloc.deallocate(this->_root, 1);
	}
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::createLeaf(value_type key) {
	node_pointer	buffer;

	buffer = this->_alloc.allocate(1);
	this->_alloc.construct(buffer, ft::node<T>(key));
	return buffer;
}

template <class T>
void	ft::BSTree<T>::addLeaf(value_type key) {
	addLeaf(key, this->_root);
}

template <class T>
void	ft::BSTree<T>::addLeaf(value_type key, node_pointer node) {
	if (this->_root == NULL) {
		this->_root = createLeaf(key);
		return ;
	}
	if (key < node->key) {
		if (node->left != NULL)
			addLeaf(key, node->left);
		else
			node->left = createLeaf(key);
	}
	else if (key > node->key) {
		if (node->right != NULL)
			addLeaf(key, node->right);
		else
			node->right = createLeaf(key);
	}
	else
		std::cerr << "Error: trying to add a key that already exist!" << std::endl;
}

template <class T>
void	ft::BSTree<T>::printInOrder() {
	printInOrder(this->_root);
}

template <class T>
void	ft::BSTree<T>::printInOrder(node_pointer node) {
	if (this->_root == NULL) {
		std::cerr << "Error: the tree is empty!";
		return ;
	}
	if (node->left != NULL)
		printInOrder(node->left);

	std::cout << node->key << " ";
	if (node->right != NULL)
		printInOrder(node->right);
}

template <class T>
void	ft::BSTree<T>::printChildren(value_type key) {
	node_pointer	node = this->findNode(key);

	if (node == NULL) {
		std::cerr << "Error: the key " << key << " isn't in the tree.";
		return ;
	}
	std::cout << "Parent: " << key << std::endl;
	node->left == NULL ? std::cout << "lChild: NULL" << std::endl : std::cout << "lChild: " << node->left->key << std::endl;
	node->right == NULL ? std::cout << "rChild: NULL" << std::endl : std::cout << "rChild: " << node->right->key << std::endl;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(value_type key) {
	return (findNode(key, this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(value_type key, node_pointer node) {
	if (node == NULL)
		return NULL;

	if (node->key == key)
		return node;
	else {
		if (key < node->key)
			return (findNode(key, node->left));
		else
			return (findNode(key, node->right));
	}
}
