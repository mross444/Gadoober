#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "worksheet24.h"

/**********************************************************************
					 linkedListIteratorInit
**********************************************************************/
void linkedListIteratorInit(struct LinkedList  *lst, struct linkedListIterator * itr) {
	itr->lst = lst;
	itr->currentLink = lst->frontSentinel->next;
}


/**********************************************************************
					linkedListIteratorHasNext
**********************************************************************/
int linkedListIteratorHasNext(struct linkedListIterator *itr) {

	/* confirm valid iterator */
	assert(itr != 0);

	/* not at the backSentinel yet */
	if (itr->currentLink != itr->lst->backSentinel) {

		/* move one link forward */
		itr->currentLink = itr->currentLink->next;
		return (1);
	}

	/* at the backSentinel */
	else return (0);

}

/**********************************************************************
					 linkedListIteratorNext
**********************************************************************/
TYPE linkedListIteratorNext(struct linkedListIterator *itr) {
	
	/* validate itr pointer is not pointed to null */
	assert(itr != 0);

	/* since the iterator has already advanced, we return the previous
	value */
	return itr->currentLink->prev->value;

}

/**********************************************************************
					linkedListIteratorRemove
**********************************************************************/
void linkedListIteratorRemove(struct linkedListIterator *itr) {

	/* validate itr pointer is not pointed to null */
	assert(itr != 0);

	/* call _removeLink for the previous value */
	removeLink(itr->lst, itr->currentLink->prev);

	/* since we call the prev value when using linkedListIteratorNext,
	no need to change the currentLink */
}

