#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "worksheet26.h"

/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue) {
	int low = 0;
	int high = size;
	int mid;

	while (low < high) {
		mid = (low + high) / 2;
		if (LT(data[mid], testValue)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return low;
}


/* These are the new functions to take advantage of the ordered dynamic array
and available to the end user , so they will be declared in the .h file */

int dyArrayBinarySearch(struct DynArr * da, TYPE testValue) {
	return _binarySearch(da->data, da->size, testValue);
}

void orderedArrayAdd(struct DynArr *da, TYPE newElement) {
	int index = _binarySearch(da->data, da->size, newElement);
	dyArrayAddAt(da, index, newElement);  /* takes care of resize if necessary*/
}


void dyArrayAddAt(struct DynArr *da, int index, TYPE newElement) {

	assert(index >= 0 && index <= da->size);
	if (da->size >= da->capacity)
		_dynArrSetCapacity(da, da->capacity * 2);
	/* you get to fill this in */

	int i;

	for (i = da->size; i > index; i--) {

		da->data[i] = da->data[i - 1];

	}

	da->data[index] = newElement;

	da->size++;

}



/* you must complete the following */

int orderedArrayContains(struct DynArr *da, TYPE testElement) {

	assert(da != 0);
	
	int idx = _binarySearch(da->data, da->size, testElement);

	if (da->data[idx] == testElement) {
		return 1;
	}

	return 0;

}

void orderedArrayRemove(struct DynArr *da, TYPE testElement) {

	assert(da != 0);

	int idx = _binarySearch(da->data, da->size, testElement);

	if (da->data[idx] == testElement) {
		removeAtDynArr(da, idx);
	}


}
