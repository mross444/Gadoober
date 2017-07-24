#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

int main() {

	struct AVLTree * myTree = createAVLTree();

	addAVLTree(myTree, 1);
	addAVLTree(myTree, 2);
	addAVLTree(myTree, 3);
	addAVLTree(myTree, 4);
	addAVLTree(myTree, 5);
	addAVLTree(myTree, 6);
	addAVLTree(myTree, 7);

	removeAVLTree(myTree, 6);
	removeAVLTree(myTree, 10);
	removeAVLTree(myTree, 4);
	removeAVLTree(myTree, 1);


	destroyAVLTree(myTree);


	return 0;

}