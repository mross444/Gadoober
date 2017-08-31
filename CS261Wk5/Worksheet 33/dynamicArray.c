/*********************************************************************
** Program Filename: dynamicArray.c
** Author:  Michael Ross
** Date:  7/17/17
** Description: Function definitions for handling dynamic array, stack, 
		and bag data structure types
** Input:  none
** Output:  console
*********************************************************************/

/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"




/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initdyArray(struct dyArray *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dyArray of cap capacity
			and 0 elements in it.		
*/
struct dyArray* newdyArray(int cap)
{
	assert(cap > 0);
	struct dyArray *r = (struct dyArray *)malloc(sizeof(struct dyArray));
	assert(r != 0);
	initdyArray(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freedyArray(struct dyArray *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deletedyArray(struct dyArray *v)
{
	freedyArray(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dyArraySetCapacity(struct dyArray *v, int newCap)
{	
	/* check validity of v */
	assert(v != 0);

	/* if capacity is less than or equal to the current 
	capacity we can just update the current capacity of v*/
	if (newCap <= v->capacity) {
		v->capacity = newCap;
		return;
	}

	/* if capacity is being increased a new array needs 
	to be initialized */
	struct dyArray *v2;
	v2 = newdyArray(newCap);

	/* Copy array values from old array into new array */
	int i;
	for (i = 0; i < v->size; i++) {
		dyArrayAdd(v2, v->data[i]);
	}

	/* free the old array, update the pointers to point 
	to the new array */
	freedyArray(v);
	v->data = v2->data;
	v->size = v2->size;
	v->capacity = v2->capacity;
	
	free(v2);
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int dyArraySize(struct dyArray *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dyArrayy is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void dyArrayAdd(struct dyArray *v, TYPE val)
{
	/* validate dyArrayy is not null */
	assert(v != 0);

	/* Check to see if a resize is necessary */
	if (v->size >= v->capacity) {
		_dyArraySetCapacity(v, 2 * v->capacity);
	}

	/* update the value at the new position and increment the size*/
	v->data[v->size] = val;
	v->size++;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE dyArrayGet(struct dyArray *v, int pos)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	/* validate index */
	assert((pos >= 0) && (pos < v->size));

	/* return the value at the stores index pos */
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void dyArrayPut(struct dyArray *v, int pos, TYPE val)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	/* validate index */
	assert((pos >= 0) && (pos < v->size));

	/* update the value at the specified position */
	v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapdyArray(struct dyArray *v, int i, int  j)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	/* validate indeces */
	assert((i >= 0) && (i < v->size) && (j >= 0) && (j < v->size));

	/* swap the value at the two indeces */
	TYPE temp = dyArrayGet(v, j);
	v->data[j] = v->data[i];
	v->data[i] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void dyArrayRemoveAt(struct dyArray *v, int idx)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

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



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dyArray is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptydyArray(struct dyArray *v)
{
	/* validate v is not null */
	assert(v != 0);

	if (v->size == 0) {  /* array is empty if size is zero */
		return 1;
	}
	else {
		return 0;
	}
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushdyArray(struct dyArray *v, TYPE val)
{
	/* confirm valid pointer */
	assert(v != 0);

	/* double size of the array if capacity is reached */
	if (v->size == v->capacity) {
		_dyArraySetCapacity(v, 2 * v->capacity);
	}

	/* add the new value to the last space of the array */
	v->data[v->size] = val;

	/* increment size of array */
	v->size++;
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topdyArray(struct dyArray *v)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	/* return the element at size - 1*/
	return v->data[(v->size - 1)];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popdyArray(struct dyArray *v)
{
	/* validate v is not null */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	/* decrement size of the array.  no need to change the value, as 
	the position will be invalid, and the value be overwritten when 
	a new value is added to the stack */
	v->size--;
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsdyArray(struct dyArray *v, TYPE val)
{
	/* check v is valid */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	int i;

	/* loop through each element of the dyArray*/
	for (i = 0; i < v->size; i++) {
		if (val == v->data[i]) {
			return 1;  /* match found - exit function */
		}
	}

	/* no match found */
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removedyArray(struct dyArray *v, TYPE val)
{
	/* check v is valid */
	assert(v != 0);

	/* validate v is not empty */
	assert(!isEmptydyArray(v));

	int i;

	for (i = 0; i < v->size; i++) {
		if (val == v->data[i]) {		/* match found */
			dyArrayRemoveAt(v, i);
			return;
		}
	}

	/* no match found - do nothing */
}