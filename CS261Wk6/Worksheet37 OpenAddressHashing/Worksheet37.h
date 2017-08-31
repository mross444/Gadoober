#define TYPE char

struct openHashTable {
	TYPE ** table;
	int tablesize;
	int count;
};

void initOpenHashTable(struct openHashTable * ht, int size);
int openHashTableSize(struct openHashTable *ht);
void openHashTableAdd(struct openHashTable * ht, TYPE  *newValue);
int openHashTableBagContains(struct openHashTable *ht, TYPE  newValue);
void _resizeOpenHashTable(struct openHashTable *ht);