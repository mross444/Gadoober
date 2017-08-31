/* 	dynamicArray_a1.h : Dynamic Array implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

struct dyArray
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

/* Dynamic Array Functions */
void initdyArray(struct dyArray *v, int capacity);	
struct dyArray *newdyArray(int cap);

void freedyArray(struct dyArray *v);
void deletedyArray(struct dyArray *v);

int dyArraySize(struct dyArray *v);

void dyArrayAdd(struct dyArray *v, TYPE val);
TYPE dyArrayGet(struct dyArray *v, int pos);
void dyArrayPut(struct dyArray *v, int pos, TYPE val);
void swapdyArray(struct dyArray *v, int i, int  j);
void dyArrayRemoveAt(struct dyArray *v, int idx);

/* Stack interface. */
int isEmptydyArray(struct dyArray *v);
void pushdyArray(struct dyArray *v, TYPE val);
TYPE topdyArray(struct dyArray *v);
void popdyArray(struct dyArray *v);

/* Bag Interface */	
/* Note dyArrayAdd is already declared above*/
int containsdyArray(struct dyArray *v, TYPE val);
void removedyArray(struct dyArray *v, TYPE val);

#endif
