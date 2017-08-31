# include "Worksheet36.h"
#include <stdlib.h>
#include <assert.h>

/*finds and places the value associated with key in valptr */
void dyArrayDictionaryGet(struct DynamicArray *da, KEYTYPE key, VALUETYPE *valptr) {

	int i;
	struct association * chkAsn;

	/* iterate through array and check for matching key */
	for (i = 0; i < dySize(da); i++) {

		chkAsn = dyGet(da, i);

		/* match found */
		if (chkAsn->key == key) {
			
			/* update the value at valptr with the value associated with the
			matching key */
			*valptr = chkAsn->value;

			return;
		}
	}

	chkAsn = 0;

}

void dyArrayDictionaryPut(struct DynamicArray *da, KEYTYPE key, VALUETYPE val) {
	struct association * ap;
	if (dyArrayDictionaryContainsKey(da, key))
		dyArrayDictionaryRemove(da, key);
	ap = (struct association *) malloc(sizeof(struct association));
	assert(ap != 0);
	ap->key = key;
	ap->value = val;
	dyAdd(da, ap);
}

int dyArrayDictionaryContainsKey(struct DynamicArray *da, KEYTYPE key) {

	int i;
	struct association * chkAsn;

	/* iterate through array and check for matching key */
	for (i = 0; i < dySize(da); i++) {

		chkAsn = dyGet(da, i);

		if (chkAsn->key == key) {
			return 1;
		}
	}

	chkAsn = 0;

	return 0;

}




void dyArrayDictionaryRemove(struct  DynamicArray *da, KEYTYPE key) {

	int i;
	struct association * chkAsn;

	/* iterate through array and check for matching key */
	for (i = 0; i < dySize(da); i++) {

		chkAsn = dyGet(da, i);

		/* if match is found */
		if (chkAsn->key == key) {
			dyRemoveAt(da, i);  /* remove the association from the array */
			free(chkAsn);	/* delete the association */
			chkAsn = 0;		
			return;		/* exit function */
		}
	}

	/* otherwise no match found, do nothing */
	chkAsn = 0;

}
