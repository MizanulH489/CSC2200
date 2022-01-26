
#include "BSTree.h"

template<typename T, class KeyType>
BSTree<T, KeyType>::BSTreeNode::BSTreeNode(const T &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr) {
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}

template<typename T, class KeyType>
BSTree<T, KeyType>::BSTree() {
	root = NULL;
}

template<typename T, class KeyType>
BSTree<T, KeyType>::BSTree(const BSTree<T, KeyType> &other) {
	root = NULL;
	copyTreeHelper(root, other.root);
}

template<typename T, class KeyType>
BSTree<T, KeyType>::~BSTree() {
	clearHelper(root);
}

template<typename T, class KeyType>
BSTree<T, KeyType>&BSTree<T, KeyType>::operator=(const BSTree<T, KeyType> &other) {
	clearHelper(root);
	copyTreeHelper(root, other.root);
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::insert(const T &newDataItem) {
	insertHelper(root, newDataItem);
}

template<typename T, class KeyType>
bool BSTree<T, KeyType>::retrieve(const KeyType &searchKey, T &searchDataItem) const {
	return retrieveHelper(root, searchKey, searchDataItem);
}

template<typename T, class KeyType>
bool BSTree<T, KeyType>::remove(const KeyType &deleteKey) {
	return removeHelper(root, deleteKey);
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::writeKeys() const {
	writeKeysHelper(root);
	cout << endl;
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::clear() {
	clearHelper(root);
	root = NULL;
}

template<typename T, class KeyType>
bool BSTree<T, KeyType>::isEmpty() const {
	return root == NULL;
}

template<typename T, class KeyType>
int BSTree<T, KeyType>::getHeight() const {
	return getHeightHelper(root) - 1;
}

template<typename T, class KeyType>
int BSTree<T, KeyType>::getCount() const {
	return getCountHelper(root);
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::writeLessThan(const KeyType &searchKey) const {
	writeLTHelper(root, searchKey);
}

// Helpers

template<typename T, class KeyType>
void BSTree<T, KeyType>::clearHelper(BSTreeNode *p) {
	if (p->left != NULL) {
		clearHelper(p->left);
	}
	if (p->right != NULL) {
		clearHelper(p->right);
	}
	delete p;
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::copyTreeHelper(BSTreeNode* &p, const BSTreeNode *otherPtr) {
	if (otherPtr == NULL) { return; }
	p = new BSTreeNode(otherPtr->nodeDataItem, NULL, NULL);
	copyTreeHelper(p->left, otherPtr->left);
	copyTreeHelper(p->right, otherPtr->right);
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::insertHelper(BSTreeNode* &p, const T &newDataItem) {
	if (p == NULL) {
		p = new BSTreeNode(newDataItem, NULL, NULL);
		return;
	}

	KeyType key = newDataItem.getKey();
	KeyType currentKey = p->dataItem.getKey();

	if (key > currentKey) {
		insertHelper(p->right, newDataItem);
	}
	else if (key < currentKey) {
		insertHelper(p->left, newDataItem);
	}
	else {
		p->dataItem = newDataItem;
	}
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::cutRightmost(BSTreeNode* &r, BSTreeNode* &delPtr) {
	if (r->right != NULL) {
		cutRightmost(r->right, delPtr);
	}
	else {
		delPtr->dataItem = r->dataItem;
		delPtr = r;
		r = r->left;
	}
}

template<typename T, class KeyType>
bool BSTree<T, KeyType>::removeHelper(BSTreeNode* &p, const KeyType &deleteKey) {
	if (p == NULL) { return false; }
	KeyType key = p->dataItem.getKey();

	if (deleteKey < key) {
		return removeHelper(p->left, deleteKey);
	}
	if (deleteKey > key) {
		return removeHelper(p->right, deleteKey);
	}

	BSTreeNode *delPtr = p;
	if (p->left == NULL) {
		p = p->right;
	}
	else if (p->right == NULL) {
		p = p->left;
	}
	else {
		cutRightmost(p->left, delPtr);
	}
	delete delPtr;
	return true;
}

template<typename T, class KeyType>
bool BSTree<T, KeyType>::retrieveHelper(BSTreeNode *p, const KeyType &searchKey, T &searchDataItem) const {
	if (p == NULL) { return false; }
	KeyType key = p->dataItem.getKey();
	if (searchKey > key) {
		return retrieveHelper(p->right, searchKey, searchDataItem);
	}
	if (searchKey < key) {
		return retrieveHelper(p->left, searchKey, searchDataItem);
	}
	searchDataItem = p->dataItem;
	return true;
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::writeKeysHelper(BSTreeNode *p) const {
	if (p == NULL) { return; }
	writeKeysHelper(p->left);
	cout << p->dataItem.getKey() << " ";
	writeKeysHelper(p->right);
}

template<typename T, class KeyType>
int BSTree<T, KeyType>::getCountHelper(BSTreeNode *p) const {
	if (p == NULL) { return 0; }
	return getCountHelper(p->left) + getCountHelper(p->right) + 1;
}

template<typename T, class KeyType>
int BSTree<T, KeyType>::getHeightHelper(BSTreeNode *p) const {
	if (p == NULL) { return 0; }
	return max(getHeightHelper(p->left), getHeightHelper(p->right)) + 1;
}

template<typename T, class KeyType>
void BSTree<T, KeyType>::writeLTHelper(BSTreeNode *p, const KeyType &searchKey) const {
	if (p == NULL) { return; }
	KeyType key = p->dataItem.getKey();
	writeLTHelper(p->left, searchKey);
	if (key < searchKey) {
		cout << key << " ";
		writeLTHelper(p->right, searchKey);
	}
}

#include "show9.cpp"
