#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* allocate memory for sentinel*/
	list->sentinel = malloc(sizeof(struct Link));

	/* assert memory was allocated */
	assert(list->sentinel != 0);

	/* sentinel's next and prev start out pointing to itself */
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

	/* size starts as zero */
	list->size = 0;

	/* END UPDATES */
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	/* BEGIN UPDATES */

	/* allocate memory for new link */
	struct Link * newLink = malloc(sizeof(struct Link));

	/* validate memory was allocated */
	assert(newLink != 0);
	
	/* set the value and pointers as NULL */
	newLink->value = value;
	newLink->next = 0;
	newLink->prev = 0;

	/* return the newLink */
	return newLink;

	/* END UPDATES */
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	/* BEGIN UPDATES */

	/* validate list and link pointers */
	assert(list != 0);
	assert(link != 0);

	/* call createLink to initialize the new link */
	struct Link * newLink = createLink(value);

	/* validate memory was allocated */
	assert(newLink != 0);

	/* newLink's next is the current prev for link */
	newLink->next= link->next;

	/* newLink's prev is the link */
	newLink->prev = link;

	/* set the link that was previously after link to now point to
	newLink as its prev */
	link->next->prev = newLink;

	/* link's new next is newLink */
	link->next = newLink;

	/* increment list size */
	list->size++;

	/* END UPDATES */
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
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
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	/* BEGIN UPDATES */

	while (!circularListIsEmpty(list))
	{
		circularListRemoveFront(list);
	}
	free(list->sentinel);
	free(list);

	/* END UPDATES */
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* call the addLinkAfter function */
	addLinkAfter(list, list->sentinel, value);

	/* END UPDATES */
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* call the addLinkAfter function */
	addLinkAfter(list, list->sentinel->prev, value);

	/* END UPDATES */
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* get the value at the front of the deque */
	return list->sentinel->next->value;

	/* END UPDATES */
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* get the value at the front of the deque */
	return list->sentinel->prev->value;

	/* END UPDATES */
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* validate list is not empty */
	assert(!circularListIsEmpty(list));

	/* call the removeLink function */
	removeLink(list, list->sentinel->next);

	/* END UPDATES */
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
	assert(list != 0);

	/* validate list is not empty */
	assert(!circularListIsEmpty(list));

	/* call the removeLink function */
	removeLink(list, list->sentinel->prev);

	/* END UPDATES */
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not pointing to NULL */
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
void circularListPrint(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not null */
	assert(list != 0);

	printf("\n\nPrinting list values...\n");

	struct Link * chkVal = list->sentinel->next;

	int i;
	for (i = 0; i < list->size; i++) {
		printf("%f", chkVal->value);
		printf("\n");
		chkVal = chkVal->next;
	}

	printf("\nPrinting list complete.\n\n");

	/* END UPDATES */
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	/* BEGIN UPDATES */

	/* validate list is not null */
	assert(list != 0);

	int i;
	struct Link * chkLnk = list->sentinel;
	struct Link * tmpLnk;

	/* loop through each value of the list and reverse the pointers */
	for (i = 0; i < list->size + 1; i++) {
		tmpLnk = chkLnk->next;
		chkLnk->next = chkLnk->prev;
		chkLnk->prev = tmpLnk;

		chkLnk = chkLnk->next;
	}

	/* END UPDATES */
}
