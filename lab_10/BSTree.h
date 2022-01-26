// --------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
// --------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T, class KeyType>
class BSTree {
	public:
		BSTree();
		BSTree(const BSTree<T, KeyType> &other);
		BSTree& operator=(const BSTree<T, KeyType> &other);

		~BSTree();

		// Binary search tree manipulation operations
		void insert(const T &newDataItem);
		bool retrieve(const KeyType &searchKey, T &searchDataItem) const;

		bool remove(const KeyType &deleteKey);
		void writeKeys() const;
		void clear();

		// Binary search tree status operations
		bool isEmpty() const;

		// Output the tree structure -- used in testing/debugging
		void showStructure() const;

		// In-lab operations
		int getHeight() const;
		int getCount() const;
		void writeLessThan(const KeyType &searchKey) const; // Output keys < searchKey

	protected:
		class BSTreeNode {
			public:
				BSTreeNode(const T &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr);
				T dataItem;
				BSTreeNode *left;
				BSTreeNode *right;
		};

		// Recursive helpers for the public member functions
		void insertHelper(BSTreeNode* &p, const T &newDataItem);
		bool retrieveHelper(BSTreeNode *p, const KeyType &searchKey, T &searchDataItem) const;
		bool removeHelper(BSTreeNode* &p, const KeyType &deleteKey);

		// cutRightmost used in one implementation of remove.
		void cutRightmost(BSTreeNode* &r, BSTreeNode* &delPtr);
		void writeKeysHelper(BSTreeNode *p) const;
		void clearHelper(BSTreeNode *p);
		void showHelper(BSTreeNode *p, int level) const;
		int  getHeightHelper(BSTreeNode *p) const;
		int  getCountHelper(BSTreeNode *p) const;
		void writeLTHelper(BSTreeNode *p, const KeyType &searchKey) const;
		void copyTree(const BSTree<T, KeyType> &otherTree);
		void copyTreeHelper(BSTreeNode* &p, const BSTreeNode *otherPtr);

		// Data member
		BSTreeNode *root;
};

#endif  // define BSTREE_H
