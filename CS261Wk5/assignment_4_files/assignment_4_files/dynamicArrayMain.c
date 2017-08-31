#include "dynamicArray.h"
#include "task.h"
#include <stdio.h>

int main() {

	struct DynamicArray* myHeap = dyNew(10);

	dyHeapAdd(myHeap, 30, taskCompare);
	dyPrint(myHeap, taskPrint);
	dyHeapAdd(myHeap, 20, taskCompare);
	dyPrint(myHeap, taskPrint);
	dyHeapAdd(myHeap, 50, taskCompare);
	dyPrint(myHeap, taskPrint);
	dyHeapAdd(myHeap, 10, taskCompare);
	dyPrint(myHeap, taskPrint);
	dyHeapAdd(myHeap, 5, taskCompare);
	dyPrint(myHeap, taskPrint);
	dyHeapAdd(myHeap, 70, taskCompare);
	dyPrint(myHeap, taskPrint);


	dyHeapRemoveMin(myHeap, taskCompare);
	dyPrint(myHeap, taskPrint);

	dyHeapAdd(myHeap, 8, taskCompare);
	dyPrint(myHeap, taskPrint);

	dyHeapRemoveMin(myHeap, taskCompare);
	dyPrint(myHeap, taskPrint);


	dyDelete(myHeap);

	printf("succes\n");

	return 0;
}