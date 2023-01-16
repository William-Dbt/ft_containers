// This part was done with the youtube tutorial by PaulProgramming channel
// The functions implementations are made with recursive method, I use the parent ptr in the node for iterators
// I don't wanted to remake thoses functions

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
ft::BSTree<T>::BSTree() : _root(NULL) {}

template <class T>
ft::BSTree<T>::BSTree(const value_type& key) {
	this->_root = this->_alloc.allocate(1);
	this->_alloc.construct(this->_root, ft::node<T>(key));
}

template <class T>
ft::BSTree<T>::~BSTree() {
	this->removeSubTree(this->_root);
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
	if (key.first < node->key.first) {
		if (node->left != NULL)
			addLeaf(key, node->left);
		else {
			node->left = createLeaf(key);
			node->left->parent = node;
		}
	}
	else if (key.first > node->key.first) {
		if (node->right != NULL)
			addLeaf(key, node->right);
		else {
			node->right = createLeaf(key);
			node->right->parent = node;
		}
	}
}

template <class T>
void	ft::BSTree<T>::printInOrder() {
	printInOrder(this->_root);
}

template <class T>
void	ft::BSTree<T>::printInOrder(node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (node->left != NULL)
		printInOrder(node->left);

	std::cout << node->key << " ";
	if (node->right != NULL)
		printInOrder(node->right);
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
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(value_type key) {
	return (findNode(key, this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findNode(value_type key, node_pointer node) {
	if (node == NULL)
		return NULL;

	if (node->key.first == key.first)
		return node;
	else {
		if (key.first < node->key.first)
			return (findNode(key, node->left));
		else
			return (findNode(key, node->right));
	}
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::getRoot() const {
	return this->_root;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findSmallest() {
	return (findSmallest(this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findSmallest(node_pointer node) {
	if (this->_root == NULL || node == NULL)
		return NULL;

	if (node->left != NULL)
		return (findSmallest(node->left));
	else
		return node;
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findGreatest() {
	return (findGreatest(this->_root));
}

template <class T>
typename ft::BSTree<T>::node_pointer	ft::BSTree<T>::findGreatest(node_pointer node) {
	if (this->_root == NULL || node == NULL)
		return NULL;

	if (node->right != NULL)
		return (findGreatest(node->right));
	else
		return node;
}

template <class T>
void	ft::BSTree<T>::removeNode(value_type key) {
	removeNode(key, this->_root);
}

template <class T>
void	ft::BSTree<T>::removeNode(value_type key, node_pointer node) {
	if (this->_root == NULL)
		return ;

	if (this->_root->key.first == key.first)
		removeRootNode();
	else {
		if (node->left != NULL && key < node->key)
			node->left->key.first == key.first ? this->removeNode(node, node->left, true) : this->removeNode(key, node->left);
		else if (node->right != NULL && key.first > node->key.first)
			node->right->key.first == key.first ? this->removeNode(node, node->right, false) : this->removeNode(key, node->right);
	}
}

template <class T>
void	ft::BSTree<T>::removeNode(node_pointer parent, node_pointer node, bool isLeft) {
	value_type	smallestKeyRightTree;

	if (this->_root == NULL)
		return ;

	if (node->left == NULL && node->right == NULL) { // Case 0: 0 children
		isLeft == true ? parent->left = NULL : parent->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left == NULL && node->right != NULL) { // Case 1: 1 child
		isLeft == true ? parent->left = node->right : parent->right = node->right;
		node->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (node->left != NULL && node->right == NULL) {
		isLeft == true ? parent->left = node->left : parent->right = node->left;
		node->left = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else { // Case 2: 2 children
		smallestKeyRightTree = this->findSmallest(node->right)->key;
		this->removeNode(smallestKeyRightTree, node);
		node->key = smallestKeyRightTree;
	}
}

template <class T>
void	ft::BSTree<T>::removeRootNode() {
	node_pointer	node;
	value_type		key, smallestKeyRightTree;

	if (this->_root == NULL)
		return ;

	node = this->_root;
	key = this->_root->key;
	if (this->_root->left == NULL && this->_root->right == NULL) { // Case 0: 0 children
		this->_root = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (this->_root->left == NULL && this->_root->right != NULL) { // Case 1: 1 child
		this->_root = this->_root->right;
		node->right = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else if (this->_root->left != NULL && this->_root->right == NULL) {
		this->_root = this->_root->left;
		node->left = NULL;
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}
	else { // Case 2: 2 children
		smallestKeyRightTree = this->findSmallest(this->_root->right)->key;
		this->removeNode(smallestKeyRightTree, this->_root);
		this->_root->key = smallestKeyRightTree;
	}
}

template <class T>
void	ft::BSTree<T>::deleteTree() {
	this->removeSubTree(this->_root->left);
	this->removeSubTree(this->_root->right);
	this->_alloc.destroy(this->_root);
	this->_alloc.deallocate(this->_root, 1);
	this->_root = NULL;
}

template <class T>
void	ft::BSTree<T>::removeSubTree(node_pointer node) {
	if (node == NULL)
		return ;

	if (node->left != NULL)
		removeSubTree(node->left);
	else if (node->right != NULL)
		removeSubTree(node->right);
	
	this->_alloc.destroy(node);
	this->_alloc.deallocate(node, 1);
}

template <class T>
size_t	ft::BSTree<T>::max_size() const {
	return this->_alloc.max_size();
}
