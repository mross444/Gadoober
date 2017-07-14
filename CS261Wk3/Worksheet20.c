#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void _dequeSetCapacity(struct deque*, int);
void dequeFree(struct deque*);
void dequeInit(struct deque*, int);
int dequeSize(struct deque*);
void dequeAddFront(struct deque*, TYPE);
void dequeAddBack(struct deque*, TYPE);
TYPE dequeFront(struct deque*);
TYPE dequeBack(struct deque *d);


struct deque {
	TYPE * data;
	int capacity;
	int size;
	int beg;
};

void _dequeSetCapacity(struct deque *d, int newCap) {
	int i;

	/* Create a new underlying array*/
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);

	/* copy elements to it */
	int j = d->beg;
	for (i = 0; i < d->size; i++)
	{
		newData[i] = d->data[j];
		j = j + 1;
		if (j >= d->capacity)
			j = 0;
	}

	/* Delete the oldunderlying array*/
	free(d->data);
	/* update capacity and size and data*/
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
}

void dequeFree(struct deque *d) {
	free(d->data); d->size = 0; d->capacity = 0;
}

void dequeInit(struct deque *d, int initCapacity) {
	d->size = d->beg = 0;
	d->capacity = initCapacity; assert(initCapacity > 0);
	d->data = (TYPE *)malloc(initCapacity * sizeof(TYPE));
	assert(d->data != 0);
}

int dequeSize(struct deque *d) { return d->size; }

void dequeAddFront(struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity) _dequeSetCapacity(d, 2 * d->capacity);

	assert(d != 0);
	int index = d->beg - 1;
	d[index] = newValue;
	d->beg -= 1;
	d->size += 1;

}

void dequeAddBack(struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity) _dequeSetCapacity(d, 2 * d->capacity);


	int index;
	index = d->beg + d->size;
	if (index >= d->capacity)
		index -= d->capacity;
	d->data[index] = newValue;
	d->size++;

}


TYPE dequeFront(struct deque *d) {

	assert(d->size >0);
	return d[d->beg];

}

TYPE dequeBack(struct deque *d) {

	int index;
	index = d->beg + d->size - 1;
	if (index >= d->capacity)
		index = index - capacity;

	return d->data[index];




}



void dequeRemoveFront(struct deque *d) {

	assert(d->size >1);
	d->beg += 1
		d->size -= 1;





}

void dequeRemoveBack(struct deque *d) {






	assert(d->size > 0);
	d->size--;





}
