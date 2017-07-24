#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "worksheet29.h"


int main() {

	struct BinarySearchTree * myTree = malloc(sizeof(struct BinarySearchTree));

	initBST(myTree);

	addBST(myTree, 1);
	addBST(myTree, 10);
	addBST(myTree, 30);
	addBST(myTree, 5);
	addBST(myTree, 15);
	addBST(myTree, 25);
	addBST(myTree, 35);

	
	printf("Contains 10?  -- %d\n", containsBST(myTree, 10));
	printf("Contains 50?  -- %d\n", containsBST(myTree, 50));
	printf("Contains 5?  -- %d\n", containsBST(myTree, 5));
	printf("Contains 15?  -- %d\n", containsBST(myTree, 15));
	printf("Contains 25?  -- %d\n", containsBST(myTree, 25));
	printf("Contains 35?  -- %d\n", containsBST(myTree, 35));
	printf("Contains 45?  -- %d\n", containsBST(myTree, 45));
	
	
	printf("\nRemoving 25...\n");
	removeBST(myTree, 25);
	printf("Contains 25?  -- %d\n", containsBST(myTree, 25));
	

	printf("\nRemoving 10...\n");
	removeBST(myTree, 10);
	printf("Contains 10?  -- %d\n", containsBST(myTree, 10));

	

	printf("\nRemoving 30...\n");
	removeBST(myTree, 30);
	printf("Contains 30?  -- %d\n", containsBST(myTree, 30));

	

	removeBST(myTree, 5);
	printf("\nRemoving 5...\n");
	printf("Contains 5?  -- %d\n", containsBST(myTree, 5));


	removeBST(myTree, 17);
	printf("\nRemoving 17...\n");
	printf("Contains 17?  -- %d\n", containsBST(myTree, 17));
	printf("Contains 15?  -- %d\n", containsBST(myTree, 15));
	

	printf("First Value  -- %d\n", getFirst(myTree));

	removeFirst(myTree);

	printf("First Value  -- %d\n", getFirst(myTree));

	removeFirst(myTree);

	printf("First Value  -- %d\n", getFirst(myTree));

	destroyBST(myTree);



	// Priority Queue implementation

	printf("\n\nStarting PQ simulation..");

	struct PriorityQueue * myPQ = createPQ();

	printf("\nQueue is empty? -- %d", isEmptyPQ(myPQ));

	printf("\nAdding values..\n\n");

	addPQ(myPQ, 10);
	addPQ(myPQ, 20);
	addPQ(myPQ, 30);
	addPQ(myPQ, 40);
	addPQ(myPQ, 45);
	addPQ(myPQ, 15);
	addPQ(myPQ, 5);
	addPQ(myPQ, 25);


	printf("Removing %d\n", frontPQ(myPQ));
	removeFrontPQ(myPQ);
	printf("Removing %d\n", frontPQ(myPQ));
	removeFrontPQ(myPQ);
	printf("Removing %d\n", frontPQ(myPQ));
	removeFrontPQ(myPQ);
	
	printf("Removing %d\n", frontPQ(myPQ));
	removeFrontPQ(myPQ);
	printf("Removing %d\n", frontPQ(myPQ));
	removeFrontPQ(myPQ);

	printf("\nQueue is empty? -- %d", isEmptyPQ(myPQ));

	destroyPQ(myPQ);

	return 0;
}