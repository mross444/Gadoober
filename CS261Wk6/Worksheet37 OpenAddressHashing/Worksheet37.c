#include "Worksheet37.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void initOpenHashTable(struct openHashTable * ht, int size) {
	int i;
	assert(size > 0);
	ht->table = (TYPE **)malloc(size * sizeof(TYPE *));
	assert(ht->table != 0);
	for (i = 0; i < size; i++)
		ht->table[i] = 0; /* initialize empty */
	ht->tablesize = size;
	ht->count = 0;
}

int openHashTableSize(struct openHashTable *ht) { return ht->count; }

void openHashTableAdd(struct openHashTable * ht, TYPE  *newValue) {
	int idx;

	/* Make sure we have space and under the load factor threshold*/
	if ((ht->count / (double)ht->tablesize) > 0.75)
		_resizeOpenHashTable(ht);
	ht->count++;

	idx = HASH(newValue) % ht->tablesize;

	/* To be safe, use only positive arithmetic.  % may behave very differently on diff
	implementations or diff languages .  However, you can do the following to deal with a
	negative result from HASH  */

	if (idx < 0) idx += ht->tablesize;












}









int openHashTableBagContains(struct openHashTable *ht, TYPE  newValue) {

	int idx;

	idx = HASH(newValue) % ht->tablesize;
	if (idx < 0) idx += ht->tablesize;




}

void _resizeOpenHashTable(struct openHashTable *ht) {



}
