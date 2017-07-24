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
						    createBST
**********************************************************************/
struct BinarySearchTree * createBST() {
	struct BinarySearchTree * newTree = malloc(sizeof(struct BinarySearchTree));
	initBST(newTree);
	return newTree;
}

/**********************************************************************
							 addBST
**********************************************************************/
void addBST(struct BinarySearchTree * tree, TYPE newValue) {
	
	assert(tree != 0);

	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}

/**********************************************************************
							 sizeBST
**********************************************************************/
int sizeBST(struct BinarySearchTree *tree) { 
	
	assert(tree != 0);
	
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
	else if (LT(newValue,current->value)) {
		current->left = _nodeAddBST(current->left, newValue);		// set the left child to be the value returned by add(leftChild, newValue)
	}

	// Otherwise (newValue is greater than the value at the start)
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

	assert(tree != 0);

	return _containsNode(tree->root, d);

}

/**********************************************************************
						  _containsNode
**********************************************************************/
int _containsNode(struct Node * current, TYPE d) {
	

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
	else if (LT(d,current->value)) {
		return _containsNode(current->left, d);
	}

	// Otherwise, go right down the tree (recursive function call)
	else {
		return _containsNode(current->right, d);
	}
}

/**********************************************************************
							removeBST
**********************************************************************/
void removeBST(struct BinarySearchTree *tree, TYPE d) {
	
	assert(tree != 0);
 
	if (containsBST(tree, d)) {
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}

}

/**********************************************************************
						 _leftMostChild
**********************************************************************/
TYPE _leftMostChild(struct Node * current) {

	// If the left child of the node we are at is null, we are at the
	// node whose value we need to return
	if (current->left == 0) {
		return current->value;
	}

	// Otherwise, we move left down the tree and call the function 
	// again (recursive function call)
	else {
		return _leftMostChild(current->left);
	}
}

/**********************************************************************
				     _removeLeftmostChild
**********************************************************************/
struct Node * _removeLeftMostChild(struct Node *current) {
	
	// If the node we are at has no left child, we are at the node we 
	// need to remove.
	if (current->left == 0) {
		
		if (current->right != 0) {
			struct Node * tmpNodePtr = current->right;	// Delete the current node
			free(current);
			current = 0;
			return tmpNodePtr;		// return the right child as the new tree
		}
		
		else {
			free(current);		// Delete the current node
			current = 0;		// Set the pointer to null
		}
	}

	// Otherwise (left child exists), we move down to the left and call
	// the function again (recursive function call).
	else {
		current->left = _removeLeftMostChild(current->left);
	}

	

	// Once finished, we return the current node.
	return current;
}


/**********************************************************************
						_nodeRemoveBST
	NOTE: value MUST exist in the BinarySearchTree.  Function should
	only be called by removeBST.
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

		// If only left child is null
		else if (current->left == 0) {
			struct Node * tmpNodePtr = current->right;	// Delete the current node
			free(current);
			current = 0;
			return tmpNodePtr;		// return the right child as the new tree
		}

		// Otherwise
		else {

			// Replace the value of node with the leftmost child of right child
			current->value = _leftMostChild(current->right);

			// set right child to be removeLeftMost(right child)
			current->right = _removeLeftMostChild(current->right);
		}
	}

	// Otherwise if value we're looking for is less than the current node's value
	else if (LT(d,current->value)) {

		// call _nodeRemoveBST on the left node (recursive call)
		current->left = _nodeRemoveBST(current->left, d);
	}

	// Otherwise (value we're looking for is greater than the current node's value)
	else {

		//call _nodeRemoveBST on the right node (recursive call)
		current->right = _nodeRemoveBST(current->right, d);

	}

	// once updates are done, return the current node
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

/**********************************************************************
						  getFirst
**********************************************************************/
TYPE getFirst(struct BinarySearchTree * tree) {
	
	assert(tree != 0);
	assert(tree->root != 0);
	
	return _leftMostChild(tree->root);
}

/**********************************************************************
						 removeFirst
**********************************************************************/
void removeFirst(struct BinarySearchTree * tree) {

	assert(tree != 0);
	assert(tree->root != 0);

	tree->root = _removeLeftMostChild(tree->root);
	tree->size--;
}


/*****************************************************************
			 createPQ - Returns a new PriorityQueue struct
*****************************************************************/
struct PriorityQueue * createPQ() { 
	struct PriorityQueue * newPQ = malloc(sizeof(struct PriorityQueue));
	initPQ(newPQ);
	return newPQ;
}

/*****************************************************************
		    initPQ - initializes the PriorityQueue
*****************************************************************/
void initPQ(struct PriorityQueue* pq) {
	pq->data = createBST();
}

/*****************************************************************
			addPQ -  Adds a value to the PriorityQueue
*****************************************************************/
void addPQ(struct PriorityQueue* pq, TYPE d) {
	addBST(pq->data, d);
}

/*****************************************************************
	frontPQ -  return the value at the front of the PQ 
	(based on priority, not on position in the struct)
*****************************************************************/
TYPE frontPQ(struct PriorityQueue* pq) {
	return getFirst(pq->data);
}

/*****************************************************************
	removeFrontPQ - removes the value returned by frontPQ
*****************************************************************/
void removeFrontPQ(struct PriorityQueue* pq) {
	removeFirst(pq->data);
}

/*****************************************************************
	isEmptyPQ -  checks if there are any items in the PQ
*****************************************************************/
int isEmptyPQ(struct PriorityQueue* pq) {
	if (sizeBST(pq->data) == 0) {
		return 1;
	}
	else return 0;
}

/*****************************************************************
	destroyPQ -  frees the memory used by the pq
*****************************************************************/
void destroyPQ(struct PriorityQueue* pq) {
	destroyBST(pq->data);
	free(pq);
	pq = 0;
}