#include "BSTree.h"

// --------------------------------------------------------------------
//
//  Laboratory 9                                         show9.cpp
//
//  Linked implementation of the showStructure operation for the
//  Binary Search Tree ADT
//
// --------------------------------------------------------------------

// --------------------------------------------------------------------

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.
template<typename T, typename KeyType>
void BSTree<T, KeyType>::showStructure() const {
	if (root == 0) {
		cout << "Empty tree" << endl;
	}
	else {
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Recursive helper for showStructure.
// Outputs the subtree whose root node is pointed to by p.
// Parameter level is the level of this node within the tree.
template<typename T, typename KeyType>
void BSTree<T, KeyType>::showHelper(BSTreeNode *p, int level) const {
	int j;   // Loop counter

	if (p != 0) {
		showHelper(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++) {  // Tab over to level
			cout << "\t";
		}
		cout << " " << p->dataItem.getKey();   // Output key
		if ((p->left != 0) &&           // Output "connector"
		    (p->right != 0)) {
			cout << "<";
		}
		else if (p->right != 0) {
			cout << "/";
		}
		else if (p->left != 0) {
			cout << "\\";
		}
		cout << endl;
		showHelper(p->left, level + 1);          // Output left subtree
	}
}
