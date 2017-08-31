# ifndef DYARRAYDICTH
# define DYARRAYDICTH

/*
dynamic array dictionary interface file
*/



# include "dynamicArray.h"

/* dictionary */
void dyArrayDictionaryGet(struct DynamicArray *da, KEYTYPE key, VALUETYPE *valptr);
void dyArrayDictionaryPut(struct DynamicArray * da, KEYTYPE key, VALUETYPE val);
int dyArrayDictionaryContainsKey(struct DynamicArray * da, KEYTYPE key);
void dyArrayDictionaryRemove(struct DynamicArray * da, KEYTYPE key);

# endif
