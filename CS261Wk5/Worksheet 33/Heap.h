#include "dynArray.h"

// Heap functions
void swap(struct dyArray*, int, int);
int indexSmallest(struct dyArray*, int, int);
TYPE heapGetFirst(struct dyArray*);
void HeapRemoveFirst(struct dyArray*);
void _adjustHeap(struct dyArray*, int, int);
void heapAdd(struct dyArray*, TYPE);
void heapPrint(struct dyArray*);

// Worksheet 34
void buildHeap(struct dyArray*);
void heapSort(struct dyArray*);