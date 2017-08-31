/*
 * CS 261 Assignment 5
 * Name: Michael Ross
 * Date: 8/14/17
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
	int i;
	HashLink * curLink;

	/* loop through each node of the table */
	for (i = 0; i < hashMapCapacity(map); i++) {

		/* check if pointer does not point to null */
		if (map->table[i] != NULL) {

			curLink = map->table[i];

			/* only one link in table */
			if (curLink->next == NULL) {
				hashLinkDelete(curLink);
			}

			else {

				while (curLink->next != NULL) {

					/* loop until 2nd to last link is reached */
					while (curLink->next->next != NULL) {
						curLink = curLink->next;
					}

					hashLinkDelete(curLink->next);

					curLink->next = NULL;

					curLink = map->table[i];

				}

				hashLinkDelete(curLink);

			}

		}

	}

	curLink = 0;
	free(map->table);

}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement	
	HashLink * cur;

	/* get the hash value */
	int i = HASH_FUNCTION(key) % map->capacity;

	
	
	/* check if there is a link initialized at the hash location */
	if (map->table[i] != NULL) {

		cur = map->table[i];

		/* loop until end of the linked list */
		while (cur != NULL) {
			
			
			//printf("key1: %s\n", cur->key);
			//printf("key2: %s\n", key);

			if (strcmp(cur->key,key) == 0) {
				
				return &(cur->value);	// value found, return its location and exit
			}

			/* go to the next link */
			cur = cur->next;
		}
	
	}

	/* key not found - return null */
    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement

	HashLink * cur;

	/* create the new map */
	HashMap * newMap = hashMapNew(capacity);

	/* loop through each bucket of the old map */
	int i;
	for (i = 0; i < map->capacity; i++) {

		/* check if the bucket has any entries */
		if (map->table[i] != NULL) {

			cur = map->table[i];

			while (cur != NULL) {

				/* add entry to the new map */
				hashMapPut(newMap, cur->key, cur->value);

				/* go to the next entry */
				cur = cur->next;
			}

		}

	}

	hashMapCleanUp(map);

	map->table = newMap->table;
	map->size = newMap->size;
	map->capacity = newMap->capacity;

	free(newMap);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement

	HashLink * cur;

	/* get the hash value */
	int i = HASH_FUNCTION(key) % map->capacity;

	//printf("i: %d\n", i);

	/* check if any nodes exist at the has value. If not, create a new node */
	if (map->table[i] == NULL) {
		map->table[i] = hashLinkNew(key, value, NULL);
		map->size++;
	}

	else {

		cur = map->table[i];

		/* loop until match is found or end of linked list is reached */
		while (cur != NULL) {

			/* check for match - if found, update the value and exit the 
			function */
			if (strcmp(cur->key, key) == 0) {
				cur->value = value;
				return;
			}


			/* check if the iterator is at the last link - if it is, 
			create a new link as the next link and exit the function */
			if (cur->next == NULL) {
				cur->next = hashLinkNew(key, value, NULL);
				map->size++;
				return;
			}

			/* otherwise, go to the next link in the list */
			cur = cur->next;

		}

	}

	/* if the max load has been reached, resize the table */
	if (hashMapTableLoad(map) > MAX_TABLE_LOAD) resizeTable(map, map->capacity * 2);

}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement

	HashLink * cur;

	/* get the hash value */
	int i = HASH_FUNCTION(key) % map->capacity;

	/* check if entries exist at the hash value */
	if (map->table[i] != NULL) {

		/* start at first entry */
		cur = map->table[i];

		/* CASE 1: Match at first entry*/
		if (strcmp(cur->key, key) == 0) {	// match found

			/* set the HashMap's first link for the index to be the next 
			value, and delete the first link */
			map->table[i] = map->table[i]->next;
			hashLinkDelete(cur);
			cur = 0;
			map->size--;
			return;
		}

		else {

			HashLink * prev = map->table[i];
			cur = cur->next;

			while (cur != NULL) {

				/* CASE 2: Match at later entry */
				if (strcmp(cur->key, key) == 0) {	// match found

					cur = cur->next;
					hashLinkDelete(prev->next);
					prev->next = cur;
					cur = 0;
					prev = 0;
					map->size--;
					return;

				}

			}

		}

	}

	/* no match found, do nothing */
	cur = 0;

}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement

	/* get the hash value */
	int i = HASH_FUNCTION(key) % map->capacity;

	/* check if entries exist at the hash value */
	if (map->table[i] != NULL) {

		HashLink * cur;

		/* start at first entry */
		cur = map->table[i];

		while (cur != NULL) {
			
			if (strcmp(cur->key, key) == 0) {	// match found
				cur = 0;
				return 1;
			}

			cur = cur->next;
		}

		cur = 0;
	}

	/* no match found - return 0 */
	return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement
	return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
	return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
	int n = 0;	// # empty buckets
	
	int i;
	for (i = 0; i < map->capacity; i++)
		if (map->table[i] == NULL) n++;

	return n;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement
	float load = hashMapSize(map) / (float)hashMapCapacity(map);

    return load;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}