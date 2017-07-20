#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


void dynArrayRemoveAt(struct dynArray *, int) {

}

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

struct dynArrayIterator {
   struct dynArray * da;
   int currentIndex; 
};

void dynArrayRemoveAt(DynArr *v, int idx)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptyDynArr(v));

	/* validate index */
	assert((idx >= 0) && (idx < v->size));

	/* Move each element in array after the idx one space to the left */
	int i;
	for (i = idx; i < v->size - 1; i++)
	{
		v->data[i] = v->data[i + 1];
	}

	/* Decrement size of array */
	v->size--;
}

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
   





}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {











}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {









}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {












}
