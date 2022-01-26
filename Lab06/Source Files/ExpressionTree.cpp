//--------------------------------------------------------------------
//
//  Laboratory 8                                  exprtree.cpp
//
//  ** SOLUTION: Linked implementation of the Expression Tree ADT **
//
//--------------------------------------------------------------------

#ifndef EXPRESSIONTREE_CPP
#define EXPRESSIONTREE_CPP

#include <stdexcept>
#include <iostream>
#include <cctype>

#include "ExpressionTree.h"

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>::ExprTreeNode:: ExprTreeNode ( char nodeDataItem,
                              ExprTreeNode *leftPtr,
                              ExprTreeNode *rightPtr )

// Creates an expreesion tree node containing data item nodeDataItem,
// left child pointer leftPtr, and right child pointer rightPtr.

{
    // create Tree node expression

    dataItem = nodeDataItem;// data item has nodedata item 
    left = leftPtr; // left child ptr has leftptr
    right = rightPtr; // right child ptr has rightPtr
}

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>:: ExprTree ()

// Creates an empty expression tree.

{
    
    root = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>:: ~ExprTree ()

// Frees the memory used by an expression tree.

{
    clear();
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>::build() 

// Builds a new expression tree from standard input (cin)

{
    clear();
    buildHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
void ExprTree<float>::buildHelper(ExprTreeNode*& p) 

// Specialized function to help build trees of floats.
// Input is single digit ints or operators.


{
    char ch;
    cin >> ch;
    // while function
    while (ch != '\n')
    {
        //&create new ExpTreeNode()
        // if function 
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            //call buildhelper for p->left and for p->right
           
            p = new ExprTreeNode(ch, NULL, NULL);
            buildHelper(p->left); // buildhlper for left p->
            buildHelper(p->right); // buildelper for right p_>
        }
        // else if function 
        else if (isdigit(ch))
        {
            p = new ExprTreeNode((float)(ch - '0'), NULL, NULL);
        }
    }
}


template <>
void ExprTree<bool>::buildHelper(ExprTreeNode*& p)

// Specialized function to help build boolean trees.
// Input is 0, 1, or operators.

{
    char ch; // Input operator or number
    cin >> ch;
    // while function to make tree
    while (ch != '\n')
    {
        if (ch == '&' || ch == '|' || ch == '^')
        {
            p = new ExprTreeNode(ch, NULL, NULL);
            buildHelper(p->left);//call buildhelper left
            buildHelper(p->right); // call buildhelper p->right
        }

        else if (isdigit(ch))     // Operator -- construct subtrees
        {
            int val = ch - '0';
            if (val == 0 || val == 1)
                p = new ExprTreeNode((bool)(val), NULL, NULL);
        }
    }
}







//--------------------------------------------------------------------

// expresiion function

template <typename DataType>
//void ExprTree<bool>::buildHelper(ExprTreeNode*& p)
void ExprTree<DataType>::expression() const 

// Public function to print out fully parenthesized expression tree.

{
    exprHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::exprHelper(ExprTreeNode* p) const 

// Private helper function to print out fully parenthesized expression tree.

{
    if ( p != 0 ) {
       if ( !isdigit(p->dataItem) ) cout << '(';
	   //call exprHelper on p left
       exprHelper(p->left);

	   //output p dataItem
       cout << (p->dataItem) << endl;
	   //call exprHelper right
           exprHelper(p->right);
	   
       if ( !isdigit(p->dataItem) ) cout << ')';
    }
}

//--------------------------------------------------------------------

template <typename DataType>
DataType ExprTree<DataType>::evaluate() const throw (logic_error) 

// Public function to evaluate an expression tree.

{
    if (!root== NULL) {
        throw logic_error("tree is empty");
    }
	
    return evalHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
float ExprTree<float>::evalHelper(ExprTreeNode* p) const 

// Private helper function to evaluate an expression tree with a float
// result.

{
    float l, r,     // Intermediate results
          result;   // Result returned

    if ( isdigit(p->dataItem) )
       result =       // Convert from char to number
    else
    {
       l = ;       // Evaluate subtrees
       r = ;
       switch ( p->dataItem )           // Combine results
       {
		 //result = l +/-/*// r
         case '+' :  result = l + r;  break;
         case '-' :  result = ;  break;
         case '*' :  result = ;  break;
         case '/' :  result = ;
       }
    }
    return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
bool ExprTree<bool>::evalHelper(ExprTreeNode* p) const 

// Private helper function to evaluate an boolean expression tree with a 
// bool result.

{
    if (isdigit(p->dataItem)) {
        return p->dataItem == '1';
    } else {
        bool l = true;
	if (p->dataItem != '-') {
	    l = evalHelper(p->left);
	}
	bool r = evalHelper(p->right);
	
	switch (p->dataItem) {
	  case '+': return l || r;
	  case '*': return l && r;
	  case '-': return !r;
	}
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>:: clear ()

// Removes all the nodes from an expression tree.

{
    clearHelper(root);
    root = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>:: clearHelper ( ExprTreeNode *p )

// Recursive helper for the clear() function. Clears the subtree
// pointed to by p.

{
    if ( p != 0 )
    {
		//call clearHelper on p left and right

       delete p;
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>:: showStructure () const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
    // No isEmpty function in this class. Add a private one if you wish.
    if ( root == 0 )		
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showHelper(root,1);
       cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>:: showHelper ( ExprTreeNode *p, int level ) const

// Recursive helper for the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
     int j;   // Loop counter

     if ( p != 0 )
     {
        showHelper(p->right,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )   // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem;        // Output dataItem
        if ( ( p->left != 0 ) &&          // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showHelper(p->left,level+1);         // Output left subtree
     }
}

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>:: ExprTree ( const ExprTree &source )

// Copy constructor. Creates a copy of valueTree.

{
	//set root to source root
	//call copyhelper on root
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source) 

// Overloads the assignment operator for any data type.

{
    if (&source != this) {
		clear();
		//set root to source root
		//call copyhelper on root
		
		
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>:: copyHelper ( ExprTreeNode *&p )

// Recursive private helper for the copy constructor and overloaded
// assignment operator. Creates a copy of the subtree pointed to by p, 
// p points to the new subtree.

{
    if ( p != 0 )
    {
		//set p to be new ExpTreeNode()
		//call copyhelper on p left and p right
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>::commute() 

// Public operator to commute the tree.

{
    commuteHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode* p) 

// Private recursive helper function to commute the tree.

{
    ExprTreeNode *temp;    // Stores pointer during swap

    if ( p != 0 )
    {
		//call commmutehelper on p left and p right
		//set temp to p left
		//p left = p right
		//p right = temp
 
    }
}

//--------------------------------------------------------------------

template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree<DataType>& source) const 

// Public operator to determine whether two expression trees are equivalent.

{
    return isEquivalentHelper(root, source.root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
bool ExprTree<DataType>::isEquivalentHelper(const ExprTreeNode* x,
					   const ExprTreeNode* y) const

// Private recursive assistant function to determine whether two expression 
// trees are equivalent.

{
    if (!x && !y) {
	return true;
    }

    if (!x || !y) {
	return false;
    }

    if (x->dataItem != y->dataItem) {
	return false;
    }

    return (   (   isEquivalentHelper(x->left, y->left)
	        && isEquivalentHelper(x->right, y->right) )
	    || (  (x->dataItem == '+' || x->dataItem == '*')
	        && isEquivalentHelper(x->right, y->left)
		&& isEquivalentHelper(x->left, y->right) ) );
}

#endif		// #ifndef EXPRESSIONTREE_CPP
