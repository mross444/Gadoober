#include "worksheet24.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	
	struct LinkedList * myArray;

	myArray = linkedListCreate();

	linkedListAdd(myArray, 0);
	linkedListAdd(myArray, 1);
	linkedListAdd(myArray, 2);
	linkedListAdd(myArray, 3);

	struct linkedListIterator * myIter;
	myIter = malloc(sizeof(struct linkedListIterator));
	linkedListIteratorInit(myArray, myIter);

	while (linkedListIteratorHasNext(myIter) != 0) {
		TYPE val = linkedListIteratorNext(myIter);
		if (val != 3) {
			printf("The next value in the array is: %d\n", val);
		}
		else {
			printf("The next value in the array is: %d\n", val);
			linkedListIteratorRemove(myIter);
		}

	}

	printf("After removing 3 \n");
	linkedListIteratorInit(myArray, myIter);

	while (linkedListIteratorHasNext(myIter) != 0) {
		printf("The next value in the array is: %d\n", linkedListIteratorNext(myIter));
	}

	free(myIter);

	linkedListDestroy(myArray);


	return 0;
}
