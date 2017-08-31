#include "Heap.h"
#include <assert.h>
#include <stdio.h>


/**********************************************************************
							swap
**********************************************************************/
void swap(struct dyArray * v, int i, int j) {  /* swap elements i j */
	TYPE temp = dyArrayGet(v, i);
	dyArrayPut(v, i, dyArrayGet(v, j));
	dyArrayPut(v, j, temp);
}

/**********************************************************************
						indexSmallest
**********************************************************************/
int indexSmallest(struct dyArray * v, int i, int j) {
	/* return index of smallest element */
	if (LT(dyArrayGet(v, i), dyArrayGet(v, j)))
		return i;
	return j;
}

/**********************************************************************
						heapGetFirst
**********************************************************************/
TYPE heapGetFirst(struct dyArray *heap) {
	assert(dyArraySize(heap) > 0);
	return dyArrayGet(heap, 0);
}

/**********************************************************************
					  HeapRemoveFirst
**********************************************************************/
void HeapRemoveFirst(struct dyArray *heap) {
	int last = dyArraySize(heap) - 1;
	assert(last != 0); /* make sure we have at least one element */
					   /* Copy the last element to the first  position */
	dyArrayPut(heap, 0, dyArrayGet(heap, last));
	dyArrayRemoveAt(heap, last);       /* Remove last element.*/
	_adjustHeap(heap, last, 0);/* Rebuild heap */
}

/**********************************************************************
						_adjustHeap
**********************************************************************/
void _adjustHeap(struct dyArray * heap, int max, int pos) {

	int leftChild = 2 * pos + 1;
	int rightChild = 2 * pos + 2;

	if (rightChild < max) {  /* we have two children */

		/* get the index of the smallest child */
		int smallest = indexSmallest(heap, leftChild, rightChild);

		if (LT(heap->data[smallest], heap->data[pos])) { /* if value at pos > value of smallest child */

			/* swap with smallest child */
			swap(heap, pos, smallest);

			/* call _adjustHeap(max, index of smallest child) */
			_adjustHeap(heap, max, smallest);
		}
	}

	else if (leftChild < max) {  /* we have one child */

		if (LT(heap->data[leftChild], heap->data[pos])) {  /* if value at pos > value of child */

			/* swap with smallest child */
			swap(heap, pos, leftChild);

			/* call adjustHeap(max, index of left child)*/
			_adjustHeap(heap, max, leftChild);
		}

	}

	/* else no children, done */
}

/**********************************************************************
						  heapAdd
**********************************************************************/
void heapAdd(struct dyArray * heap, TYPE newValue) {
	
	dyArrayAdd(heap, newValue); /* adds to end – now need to adjust position */

	/* start at the end */
	int idx = dyArraySize(heap) - 1;

	/*
	printf("\n\nDEBUGGING\nidx = %d\n", idx);
	printf("parent idx = %d\n", idx / 2 - 1 + idx % 2);
	printf("value at idx = %d\n", heap->data[idx]);
	printf("value at parent idx = %d\n", heap->data[idx / 2 - 1 + idx % 2]);
	printf("END DEBUGGING\n\n");
	*/

	/* starting at the end node, go up the tree calling _adjustHeap until 
	either the top of the tree is reached or the value of the parent node
	is less than that of the child node */
	while ((idx / 2 - 1 + idx % 2) >= 0 && LT(heap->data[idx], heap->data[idx / 2 - 1 + idx % 2])) {
		swap(heap, idx, idx / 2 - 1 + idx % 2);
		idx = idx / 2 - 1 + idx % 2;
		_adjustHeap(heap, dyArraySize(heap), idx);
	}


}

/**********************************************************************
						  heapPrint
**********************************************************************/
void heapPrint(struct dyArray * heap) {

	printf("Printing Heap...\n\n");

	int i;
	for (i = 0; i < dyArraySize(heap); i++) {
		printf("%d\n", heap->data[i]);
	}

	printf("\nHeap printing complete.\n\n");
}


/**********************************************************************
						  buildHeap
**********************************************************************/
void buildHeap(struct dyArray * heap) {
	
	int max = dyArraySize(heap);

	int i;
	for (i = max / 2 - 1; i >= 0; i--) {
		_adjustHeap(heap, max, i);
	}
}

/**********************************************************************
						  heapSort
**********************************************************************/
void heapSort(struct dyArray * v) {
	
	buildHeap(v);
	
	int i;
	int max = dyArraySize(v);

	for (i = max - 1; i >= 0; i--) {
		swap(v, 0, i);
		_adjustHeap(v, i, 0);
	}

	// We now have an array in descending order, which we need to reverse
	for (i = 0; i < max /2; i++) {
		swap(v, i, max - 1 - i);
	}

}