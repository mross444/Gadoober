#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "worksheet29.h"

/**********************************************************************
							initBST
**********************************************************************/
void initBST(struct BinarySearchTree * tree) { 
	tree->size = 0; tree->root = 0;
}

/**********************************************************************
							 addBST
**********************************************************************/
void addBST(struct BinarySearchTree * tree, TYPE newValue) {
	tree->root = _nodeAddBST(tree->root, newValue);  
	tree->size++;
}

/**********************************************************************
							 sizeBST
**********************************************************************/
int sizeBST(struct BinarySearchTree *tree) { 
	return tree->size; 
}

/**********************************************************************
						   _nodeAddBST
**********************************************************************/
struct Node * _nodeAddBST(struct Node * current, TYPE newValue) {

	// If current is null, return a new Node with newValue
	if (current == 0) {
		struct Node * newNode = malloc(sizeof(struct Node));
		newNode->value = newValue;
		newNode->left = 0;
		newNode->right = 0;
		return newNode;
	}

	// Otherwise, if newValue is less than the value at start
	else if (newValue < current->value) {
		current->left = _nodeAddBST(current->left, newValue);		// set the left child to be the value returned by add(leftChild, newValue)
	}

	// Otherwise
	else {
		current->right = _nodeAddBST(current->right, newValue);		// set the right child to be add(rightChild, newValue)
	}

	// Return the current node
	return current;
}

/**********************************************************************
						   containsBST
**********************************************************************/
int containsBST(struct BinarySearchTree * tree, TYPE d) {

	return _containsNode(tree->root, d);

}

/**********************************************************************
						   containsNode
**********************************************************************/
int _containsNode(struct Node * current, TYPE d) {
	if (current == 0) {
		return 0;
	}

	// Return true if there is a match
	else if (current->value == d) {
		return 1;
	}

	// Otherwise, if the chkValue is less than the value of the node,
	// go left down the tree
	else if (d < current->value) {

		return _containsNode(current->left, d);
	}

	// Otherwise, go right down the tree
	else {
		return _containsNode(current->right, d);
	}
}

/**********************************************************************
							removeBST
**********************************************************************/
void removeBST(struct BinarySearchTree *tree, TYPE d) {
	if (containsBST(tree, d)) {
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}
}

/**********************************************************************
						 _leftMostChild
**********************************************************************/
TYPE _leftMostChild(struct Node * current) {

	assert(current != 0);

	if (current->left == 0) {
		return current->value;
	}

	else {
		return _leftMostChild(current->left);
	}
}

/**********************************************************************
				     _removeLeftmostChild
**********************************************************************/
struct Node * _removeLeftMostChild(struct Node *current) {
	
	if (current->left == 0) {
		free(current);
		current = 0;
	}

	else {
		_removeLeftMostChild(current->left);
	}

	return current;
}




/**********************************************************************
						_nodeRemoveBST
**********************************************************************/
struct Node *  _nodeRemoveBST(struct Node * current, TYPE d) {

	// If start value is the value we seek
	if (d == current->value) {
		
		// If both left and right are null
		if (current->right == 0 && current->left == 0) {
			free(current);
			return 0;
		}

		// If only right child is null
		else if (current->right == 0) {

			struct Node * tmpNodePtr = current->left;	// Delete the current node
			free(current);
			current = 0;
			return tmpNodePtr;		// return the left child as the new tree
		}

		// Otherwise
		else {

			// Replace the value of node with the leftmost child of right child
			current->value = _leftMostChild(current->right);

			// set right child to be removeLeftMost(right child)
			current->right = _removeLeftMostChild(current->right);
		}
	}

	// Otherwise if testValue is smaller thean start value
	else if (d < current->value) {

		//set left child to remove(leftChild, testValue)
		current->left = _nodeRemoveBST(current->left, d);
	}

	// Otherwise
	else {

		//set right child to remove(rightChild, testValue)
		current->right = _nodeRemoveBST(current->right, d);

	}

	// return the current node
	return current;

}

/**********************************************************************
						  destroyBST
**********************************************************************/
void destroyBST(struct BinarySearchTree * tree) {
	_destroyBST(tree->root);
	free(tree);
	tree = 0;
}

/**********************************************************************
						 _destroyBST
**********************************************************************/
void _destroyBST(struct Node * current) {
	if (current != 0) {
		_destroyBST(current->left);
		_destroyBST(current->right);
		free(current);
	}
}