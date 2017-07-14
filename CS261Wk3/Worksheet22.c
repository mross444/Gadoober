#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct dLink {
	TYPE value;
	struct dLink * next;
	struct dLink * prev;
};

struct linkedList {
	struct dLink * frontSentinel;
	struct dLink * backSentinel;
	int size;
};

/* prototypes */
void linkedListInit(struct linkedList*);
void linkedListFree(struct linkedList*);
void _addLink(struct linkedList*, struct dLink*, TYPE);
void _removeLink(struct linkedList*, struct dLink*);
void linkedListAdd(struct linkedList*, TYPE);
int linkedListContains(struct linkedList*, TYPE);
void linkedListRemove(struct linkedList*, TYPE); 
void linkedListRemoveFront(struct linkedList*);
int linkedListIsEmpty(struct linkedList*);


/**********************************************************************
                          linkedlistInit
**********************************************************************/
void linkedListInit(struct linkedList * lst) {

	/* allocate memory for frontSentinel*/
	lst->frontSentinel = malloc(sizeof(struct dLink));

	/* assert memory was allocated */
	assert(lst->frontSentinel != 0);

	/* allocate memory for backSentinel */
	lst->backSentinel = malloc(sizeof(struct dLink));

	/* assert memory was allocated */
	assert(lst->backSentinel);

	/* frontSentinel's "next" is backSentinel */
	lst->frontSentinel->next = lst->backSentinel;

	/* backSentinel's "prev" is frontSentinel*/
	lst->backSentinel->prev = lst->frontSentinel;

	/* size starts as zero */
	lst->size = 0;
}

/**********************************************************************
						 linkedListIsEmpty
**********************************************************************/
int linkedListIsEmpty(struct linkedList *q) {
	return q->size == 0;
}


/**********************************************************************
						linkedListRemoveFront
**********************************************************************/
void linkedListRemoveFront(struct linkedList *q) {
	assert(!linkedListIsEmpty(q));
	_removeLink(q, q->frontSentinel->next);
}

/**********************************************************************
                          linkedListFree
**********************************************************************/
void linkedListFree(struct linkedList * lst) {
	while (lst->size > 0) {
		linkedListRemoveFront(lst);
	}
		
	free(lst->frontSentinel);
	free(lst->backSentinel);
	lst->frontSentinel = lst->backSentinel = NULL;
}

/**********************************************************************
                             _addLink
**********************************************************************/
void _addLink(struct linkedList * lst, struct dLink * lnk, TYPE e) {
	
	/* Check that lst is valid */
	assert(lst != 0);

	/* Check that the lnk is valid */
	assert(lnk != 0);

	/* allocate memory for newLink*/
	struct dLink * newLink = malloc(sizeof(struct dLink));

	/* assert memory was allocated */
	assert(newLink != 0);

	/* newLink's prev is the current prev for lnk */
	newLink->prev = lnk->prev;

	/* newLink's next is the lnk */
	newLink->next = lnk;

	/* set value */
	newLink->value = e;

	/* set the link that was previously before lnk to now point to 
	newLink as its next */
	lnk->prev->next = newLink;

	/* lnk's new prev is newLink */
	lnk->prev = newLink;

	/* increment lst size */
	lst->size++;
}

/**********************************************************************
                            _removeLink
**********************************************************************/
void _removeLink(struct linkedList * lst, struct dLink * lnk) {
	
	/* Check that lst is valid */
	assert(lst != 0);

	/* Check that the lnk is valid */
	assert(lnk != 0);
	
	/* For element to be removed, updated its previous element's
	next pointer to point to the element after the one to be
	removed */
	lnk->prev->next = lnk->next;

	/* For element to be removed, updated its next element's
	prev pointer to point to the element before the one to be
	removed */
	lnk->next->prev = lnk->prev;

	/* Remove the link and free the memory */
	free(lnk);

	/* Decrement size of the list*/
	lst->size--;
}

/**********************************************************************
                           linkedListAdd
**********************************************************************/
void linkedListAdd(struct linkedList * lst, TYPE e)
{
	_addLink(lst, lst->frontSentinel->next, e);
}

/**********************************************************************
                          linkedListContains
**********************************************************************/
int linkedListContains(struct linkedList *lst, TYPE e) {

	/* check lst is valid */
	assert(lst != 0);

	/* define chkLnk pointer, start at value after frontSentinel */
	struct dLink* chkLnk = lst->frontSentinel->next;

	int i;

	/* loop through each element of the list*/
	for (i = 0; i < lst->size; i++) {
		if (e == chkLnk->value) {
			return 1;  /* match found - exit function */
		}

		/* go to the next element */
		chkLnk = chkLnk->next;
	}

	/* no match found */
	return 0;
}

/**********************************************************************
                          linkedListRemove
**********************************************************************/
void linkedListRemove(struct linkedList *lst, TYPE e) {

	/* check lst is valid */
	assert(lst != 0);

	/* define chkLnk pointer, start at value after frontSentinel */
	struct dLink* chkLnk = lst->frontSentinel->next;

	int i;

	/* loop through each element of the list*/
	for (i = 0; i < lst->size; i++) {
		if (e == chkLnk->value) {
			_removeLink(lst, chkLnk);
			return;  /* match found - exit function */
		}

		/* go to the next element */
		chkLnk = chkLnk->next;
	}

	/* no match found  - do nothing*/
}


/**********************************************************************
								main
**********************************************************************/
int main() {
	struct linkedList myData;

	linkedListInit(&myData);

	linkedListAdd(&myData, 10);
	linkedListAdd(&myData, 20);
	linkedListAdd(&myData, 30);

	int a;

	a = linkedListContains(&myData, 10);

	printf("Contains 10: ");
	printf("%d", a);
	printf("\n\n");

	a = linkedListContains(&myData, 15);

	printf("Contains 15: ");
	printf("%d", a);
	printf("\n\n");

	linkedListAdd(&myData, 10);
	linkedListRemove(&myData, 10);
	a = linkedListContains(&myData, 10);

	printf("Contains 10: ");
	printf("%d", a);
	printf("\n\n");

	linkedListFree(&myData);

	return 0;
}
