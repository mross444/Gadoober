#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

/**********************************************************************
initAVLTree
**********************************************************************/
void initAVLTree(struct AVLTree * tree) {
	tree->size = 0; tree->root = 0;
}

/**********************************************************************
createAVLTree
**********************************************************************/
struct AVLTree * createAVLTree() {
	struct AVLTree * newTree = malloc(sizeof(struct AVLTree));
	initAVLTree(newTree);
	return newTree;
}

/**********************************************************************
sizeAVLTree
**********************************************************************/
int sizeAVLTree(struct AVLTree * tree) {

	assert(tree != 0);

	return tree->size;
}

/**********************************************************************
destroyAVLTree
**********************************************************************/
void destroyAVLTree(struct AVLTree * tree) {
	_destroyAVLTree(tree->root);
	free(tree);
	tree = 0;
}

/**********************************************************************
_destroyAVLTree
**********************************************************************/
void _destroyAVLTree(struct AVLnode * current) {
	if (current != 0) {
		_destroyAVLTree(current->left);
		_destroyAVLTree(current->right);
		free(current);
	}
}

/**********************************************************************
addAVLTree
**********************************************************************/
void addAVLTree(struct AVLTree * tree, TYPE newValue) {

	assert(tree != 0);

	tree->root = _AVLnodeAdd(tree->root, newValue);
	tree->size++;
}

/**********************************************************************
containsAVLTree
**********************************************************************/
int containsAVLTree(struct AVLTree * tree, TYPE d) {

	assert(tree != 0);

	return _containsAVLnode(tree->root, d);

}

/**********************************************************************
_containsAVLnode
**********************************************************************/
int _containsAVLnode(struct AVLnode * current, TYPE d) {


	//if we are at a null node, return false
	if (current == 0) {
		return 0;
	}

	// Return true if there is a match
	else if (current->value == d) {
		return 1;
	}

	// Otherwise, if the chkValue is less than the value of the node,
	// go left down the tree (recursive function call)
	else if (LT(d, current->value)) {
		return _containsAVLnode(current->left, d);
	}

	// Otherwise, go right down the tree (recursive function call)
	else {
		return _containsAVLnode(current->right, d);
	}
}

/**********************************************************************
		_h -- returns the height of the provided AVLnode
**********************************************************************/
int _h(struct AVLnode * current)
{
	if (current == 0) {
		return -1;
	}

	return current->height;
}

/**********************************************************************
	_setHeight -- set the provided AVLnode's height based on the 
	heights of its child nodes.
**********************************************************************/
void _setHeight(struct AVLnode * current) {
	int lch = _h(current->left);
	int rch = _h(current->right);
	if (lch < rch) current->height = 1 + rch;
	else current->height = 1 + lch;
}

/**********************************************************************
			_AVLnodeAdd -- adds a node to the AVLTree
**********************************************************************/
struct AVLnode * _AVLnodeAdd(struct AVLnode* current, TYPE newValue) {
	struct AVLnode * newnode;
	if (current == 0) {
		newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
		assert(newnode != 0);
		newnode->value = newValue;
		newnode->left = newnode->right = 0;
		newnode->height = 0;	// added this
		return newnode;  //why don’t we balance here ??
	}
	else if (LT(newValue, current->value))
		current->left = _AVLnodeAdd(current->left, newValue);
	else current->right = _AVLnodeAdd(current->right, newValue);
	return _balance(current);    /* <-   NEW  the call on balance */
}

/**********************************************************************
	_bf -- returns the difference in height between the provided
	node's right child node and its left child node
**********************************************************************/
int _bf(struct AVLnode * current)
{
	return _h(current->right) - _h(current->left);
}

/**********************************************************************
	_balance -- 
**********************************************************************/
struct AVLnode * _balance(struct AVLnode * current) {

	/* get the difference in height between the current node's left
	and right child nodes */
	int cbf = _bf(current);

	/* if _h(left) is at least 2 greater than _h(right) */
	if (cbf < -1) {
		if (_bf(current->left) > 0) // double rotation
			current->left = _rotateLeft(current->left);
		return _rotateRight(current); // single rotation
	}

	/* otherwise, if _h(right) is at least 2 greater than _h(left) */
	else if (cbf > 1) {
		if (_bf(current->right) < 0)
			current->right = _rotateRight(current->right);
		return _rotateLeft(current);
	}

	

	/* update the height */
	_setHeight(current);

	/* return the node we started at */

	return current;
}

/**********************************************************************
_rotateLeft
**********************************************************************/
struct AVLnode * _rotateLeft(struct AVLnode * current) {

	struct AVLnode * y = current->right;
	struct AVLnode * t2 = y->left;

	y->left = current;
	current->right = t2;

	return y;
}

/**********************************************************************
_rotateRight
**********************************************************************/
struct AVLnode * _rotateRight(struct AVLnode * current) {

	struct AVLnode * y = current->left;
	struct AVLnode * t3 = y->right;

	y->right = current;
	current->left = t3;

	return y;
}

/**********************************************************************
removeAVLTree
**********************************************************************/
void removeAVLTree(struct AVLTree *tree, TYPE val) {
	if (containsAVLTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->size--;
	}
}

/**********************************************************************
_leftMost
**********************************************************************/
TYPE _leftMost(struct AVLnode * cur) {
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur->value;
}

/**********************************************************************
_removeLeftmost
**********************************************************************/
struct AVLnode * _removeLeftmost(struct AVLnode *cur) {
	struct AVLnode *temp;

	if (cur->left != 0)
	{
		cur->left = _removeLeftmost(cur->left);
		return _balance(cur);
	}

	temp = cur->right;
	free(cur);
	return temp;
}

/**********************************************************************
_removeNode
**********************************************************************/
struct AVLnode * _removeNode(struct AVLnode *cur, TYPE val) {

	// If start value is the value we seek
	if (val == cur->value) {

		// If both left and right are null
		if (cur->right == 0 && cur->left == 0) {
			free(cur);
			return 0;
		}

		// If only right child is null
		else if (cur->right == 0) {
			struct AVLnode * tmpNodePtr = cur->left;	// Delete the current node
			free(cur);
			cur = 0;
			return tmpNodePtr;		// return the left child as the new tree
		}

		// If only left child is null
		else if (cur->left == 0) {
			struct AVLnode * tmpNodePtr = cur->right;	// Delete the current node
			free(cur);
			cur = 0;
			return tmpNodePtr;		// return the right child as the new tree
		}

		// Otherwise
		else {

			// Replace the value of node with the leftmost child of right child
			cur->value = _leftMost(cur->right);

			// set right child to be removeLeftMost(right child)
			cur->right = _removeLeftmost(cur->right);
		}
	}

	// Otherwise if value we're looking for is less than the current node's value
	else if (LT(val, cur->value)) {

		// call _nodeRemoveBST on the left node (recursive call)
		cur->left = _removeNode(cur->left, val);
	}

	// Otherwise (value we're looking for is greater than the current node's value)
	else {

		//call _nodeRemoveBST on the right node (recursive call)
		cur->right = _removeNode(cur->right, val);

	}

	// once updates are done, return the current node
	return _balance(cur);
}
