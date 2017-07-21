#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "worksheet26.h"


int main() {

	struct DynArr * myArray = newDynArr(10);

	addDynArr(myArray, 1);
	addDynArr(myArray, 3);
	addDynArr(myArray, 5);
	addDynArr(myArray, 7);
	addDynArr(myArray, 9);

	int x = _binarySearch(myArray->data, myArray->size, 9);
	printf("9 found at index %d\n", x);

	printf("\nCalling add 10...");

	orderedArrayAdd(myArray,10);

	printf("\n\nNew array: ");

	for (x = 0; x < myArray->size; x++) {
		printf("%d", myArray->data[x]);
		printf("   ");
	}

	printf("\n\nCalling remove 3...");

	orderedArrayRemove(myArray, 3);

	printf("\n\nNew array: ");

	for (x = 0; x < myArray->size; x++) {
		printf("%d", myArray->data[x]);
		printf("   ");
	}

	printf("\n\nArray contains 4: %d\n", orderedArrayContains(myArray, 4));
	printf("Array contains 5: %d\n", orderedArrayContains(myArray, 5));

	deleteDynArr(myArray);

	printf("\n\n");

	return 0;
}