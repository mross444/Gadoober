#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	
	/* BEGIN UPDATES */

	/* allocate memory for frontSentinel*/
	list->frontSentinel = malloc(sizeof(struct Link));

	/* assert memory was allocated */
	assert(list->frontSentinel != 0);

	/* allocate memory for backSentinel */
	list->backSentinel = malloc(sizeof(struct Link));

	/* assert memory was allocated */
	assert(list->backSentinel);

	/* frontSentinel's "next" is backSentinel */
	list->frontSentinel->next = list->backSentinel;

	/* backSentinel's "prev" is frontSentinel*/
	list->backSentinel->prev = list->frontSentinel;

	/* size starts as zero */
	list->size = 0;


	/* END UPDATES */
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	/* BEGIN UPDATES */

	/* Check that list is valid */
	assert(list != 0);

	/* Check that the link is valid */
	assert(link != 0);

	/* allocate memory for newLink*/
	struct Link * newLink = malloc(sizeof(struct Link));

	/* assert memory was allocated */
	assert(newLink != 0);

	/* newLink's prev is the current prev for link */
	newLink->prev = link->prev;

	/* newLink's next is the link */
	newLink->next = link;

	/* set value */
	newLink->value = value;

	/* set the link that was previously before link to now point to
	newLink as its next */
	link->prev->next = newLink;

	/* link's new prev is newLink */
	link->prev = newLink;

	/* increment list size */
	list->size++;

	/* END UPDATES */
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	/* BEGIN UPDATES */

	/* Check that list is valid */
	assert(list != 0);

	/* Check that the link is valid */
	assert(link != 0);

	/* For element to be removed, updated its previous element's
	next pointer to point to the element after the one to be
	removed */
	link->prev->next = link->next;

	/* For element to be removed, updated its next element's
	prev pointer to point to the element before the one to be
	removed */
	link->next->prev = link->prev;

	/* Remove the link and free the memory */
	free(link);

	/* Decrement size of the list*/
	list->size--;

	/* END UPDATES */
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	/* make update */
	addLinkBefore(list, list->frontSentinel->next, value);

	/* END UPDATES */
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	/* BEGIN UPDATES 
	*/
	/* validate list */
	assert(list != 0);

	/* make update */
	addLinkBefore(list, list->backSentinel, value);

	/* END UPDATES */
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	/* get and return the requested value */
	return list->frontSentinel->next->value;

	/* END UPDATES */
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	/* get and return the requested value */
	return list->backSentinel->prev->value;

	/* END UPDATES */
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	/* validate list is not empty */
	assert(!linkedListIsEmpty(list));

	/* call the removeLink function for the front element */
	removeLink(list, list->frontSentinel->next);

	/* END UPDATES */
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	/* validate list is not empty */
	assert(!linkedListIsEmpty(list));

	/* call the removeLink function for the back element */
	removeLink(list, list->backSentinel->prev);

	/* END UPDATES */
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list */
	assert(list != 0);

	if (list->size == 0) {
		return 1;
	}

	return 0;

	/* END UPDATES */
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not null */
	assert(list != 0);

	printf("\n\nPrinting list values...\n");
	
	struct Link * chkVal = list->frontSentinel->next;

	int i;
	for (i = 0; i < list->size; i++) {
		printf("%d", chkVal->value);
		printf("\n");
		chkVal = chkVal->next;
	}

	printf("\nPrinting list complete.\n\n");

	/* END UPDATES */
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* validate list is not null */
	assert(list != 0);

	linkedListAddFront(list, value);

	/* END UPDATES */
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* check list is valid */
	assert(list != 0);

	/* define chkLnk pointer, start at value after frontSentinel */
	struct Link* chkLnk = list->frontSentinel->next;

	int i;

	/* loop through each element of the list*/
	for (i = 0; i < list->size; i++) {
		if (value == chkLnk->value) {
			return 1;  /* match found - exit function */
		}

		/* go to the next element */
		chkLnk = chkLnk->next;
	}

	/* no match found */
	return 0;

	/* END UPDATES */
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* check list is valid */
	assert(list != 0);

	/* define chkLnk pointer, start at value after frontSentinel */
	struct Link* chkLnk = list->frontSentinel->next;

	int i;

	/* loop through each element of the list*/
	for (i = 0; i < list->size; i++) {
		if (value == chkLnk->value) {
			removeLink(list, chkLnk);
			return;  /* match found - exit function */
		}

		/* go to the next element */
		chkLnk = chkLnk->next;
	}

	/* no match found  - do nothing*/

	/* END UPDATES */
}
