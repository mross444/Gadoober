/*
 * CS 261 Assignment 5
 * Name: Michael Ross
 * Date: 8/14/17
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}


/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---

	FILE * fp;
	fp = fopen(fileName, "r");

	if (fp == 0) {
		printf("File does not exit.  Load failed.\n\n");
	}

	else {

		char * wordIdx = nextWord(fp);

		while (wordIdx != NULL) {
			// check if key already exists 
			if (hashMapContainsKey(map, wordIdx) == 1) {

				// get the current count and increment it by 1 
				int * iptr = hashMapGet(map, wordIdx);
				hashMapPut(map, wordIdx, *iptr + 1);
				iptr = 0;
			}

			// otherwise, add the word with a value of 1 
			else {
				hashMapPut(map, wordIdx, 1);
			}

			free(wordIdx);
			wordIdx = nextWord(fp);
		}

		wordIdx = 0;

		// print summary 
		int i;
		HashLink * cur;
		for (i = 0; i < map->capacity; i++) {
			if (map->table[i] != NULL) {
				cur = map->table[i];
				while (cur != NULL) {
					printf("%s: %d\n", cur->key, cur->value);
					cur = cur->next;
				}
			}
		}
		
		cur = 0;
		fclose(fp);

	}

    // Be sure to free the word after you are done with it here.
    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}
