# include "Worksheet36.h"
#include <stdio.h>

int main() {

	struct DynamicArray * myDictionary = dyNew(5);

	dyArrayDictionaryPut(myDictionary, "a1", 10.0);
	dyArrayDictionaryPut(myDictionary, "b2", 20.0);
	dyArrayDictionaryPut(myDictionary, "c3", 30.0);
	dyArrayDictionaryPut(myDictionary, "d4", 40.0);
	dyArrayDictionaryPut(myDictionary, "e5", 50.0);


	double myVal = 5.0;
	double * myValPtr = &myVal;



	dyArrayDictionaryGet(myDictionary, "e5", myValPtr);

	printf("myVal: %f\n", *myValPtr);

	dyArrayDictionaryGet(myDictionary, "d4", myValPtr);

	printf("myVal: %f\n", *myValPtr);

	dyArrayDictionaryRemove(myDictionary, "c2");
	dyArrayDictionaryRemove(myDictionary, "c3");

	dyArrayDictionaryGet(myDictionary, "c3", myValPtr);

	printf("myVal: %f\n", *myValPtr);

	dyDelete(myDictionary);

	printf("done\n\n");

	return 0;
}