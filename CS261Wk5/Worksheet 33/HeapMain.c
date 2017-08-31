#include "Heap.h"
#include <stdio.h>

int main() {

	struct dyArray* myHeap = newdyArray(10);

	/*
	heapAdd(myHeap, 30);
	heapPrint(myHeap);
	heapAdd(myHeap, 20);
	heapPrint(myHeap);
	heapAdd(myHeap, 50);
	heapPrint(myHeap);
	heapAdd(myHeap, 10);
	heapPrint(myHeap);
	heapAdd(myHeap, 5);
	heapPrint(myHeap);
	heapAdd(myHeap, 70);
	heapPrint(myHeap);

	
	HeapRemoveFirst(myHeap);
	heapPrint(myHeap);

	heapAdd(myHeap, 8);
	heapPrint(myHeap);

	HeapRemoveFirst(myHeap);
	heapPrint(myHeap);

	buildHeap(myHeap);
	heapPrint(myHeap);
	*/

	int i;
	for (i = 0; i < 30; i++) {
		dyArrayAdd(myHeap, i);
	}


	heapSort(myHeap);
	heapPrint(myHeap);


	deletedyArray(myHeap);

	printf("succes\n");

	return 0;
}