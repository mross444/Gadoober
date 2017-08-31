#include "hashMap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	/* create the map */
	struct HashMap * myHashMap = hashMapNew(7);


	/* add values */

	hashMapPut(myHashMap, "a1", 10);
	hashMapPut(myHashMap, "a2", 20);
	hashMapPut(myHashMap, "a3", 20);
	hashMapPut(myHashMap, "a4", 20);
	hashMapPut(myHashMap, "b2", 20);


	/* get values */
	int * valptr;

	valptr = hashMapGet(myHashMap, "a1");

	if (valptr != 0) {
		printf("%d\n", *valptr);
	}
	
	else {
		printf("key not found\n");
	}

	valptr = hashMapGet(myHashMap, "b2");

	if (valptr != 0) {
		printf("%d\n", *valptr);
	}

	else {
		printf("key not found\n");
	}

	valptr = hashMapGet(myHashMap, "c3");

	if (valptr != 0) {
		printf("%d\n", *valptr);
	}

	else {
		printf("key not found\n");
	}
	

	hashMapPrint(myHashMap);

	printf("size: %d\n", hashMapSize(myHashMap));
	printf("capacity: %d\n", hashMapCapacity(myHashMap));
	printf("load: %f\n", hashMapTableLoad(myHashMap));

	resizeTable(myHashMap, 12);

	hashMapPrint(myHashMap);

	printf("size: %d\n", hashMapSize(myHashMap));
	printf("capacity: %d\n", hashMapCapacity(myHashMap));
	printf("load: %f\n", hashMapTableLoad(myHashMap));

	/* delete the map */
	hashMapDelete(myHashMap);
	
	/* done */
	printf("done\n");

	return 0;
}