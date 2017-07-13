#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void linkedListStackInit(struct linkedListStack*);
void linkedListStackFree(struct linkedListStack*);
void linkedListStackPush(struct linkedListStack*, TYPE);
TYPE linkedListStackTop(struct linkedListStack*);
void linkedListStackPop(struct linkedListStack*);
int linkedListStackIsEmpty(struct linkedListStack*);

struct link {
	TYPE value;
	struct link * next;
};

struct linkedListStack {
	struct link *firstLink;
};

void linkedListStackInit(struct linkedListStack * s)
{
	s->firstLink = 0;
}

void linkedListStackFree (struct linkedListStack *s)
	{ while (! linkedListStackIsEmpty(s)) linkedListStackPop(s);  }

void linkedListStackPush (struct linkedListStack *s, TYPE d)  {
	struct link * newLink = (struct link *) malloc(sizeof(struct link));
	assert (newLink != 0);
	
	/* Fix me */
	assert(s != 0);

	/* Set newLink value */
	newLink->value = d;

	/* Set newLink to point to current top record */
	if (linkedListStackIsEmpty(s) == 1) {
		newLink->next = 0;
	}
	else {
		newLink->next = s->firstLink;
	}
	
	/* Set newLink as the new top record */
	s->firstLink = newLink;

	/* END UPDATES */
}

TYPE linkedListStackTop(struct linkedListStack *s) {
	
	/* Fix me */
	assert(s != 0);

	/* return the top value */
	return s->firstLink->value;

	/* END UPDATES */
}

void linkedListStackPop(struct linkedListStack *s) {

	/* Fix me */
	assert(s != 0);

	if (linkedListStackIsEmpty(s) == 0) {	/* only perform action if stack is not empty */
		/* Use a temp pointer to track top value */
		struct link * tempLinkPtr = s->firstLink;

		/* Update the linkedListStack to point to the next value
		as the new firstLink */
		s->firstLink = s->firstLink->next;

		/* Free the memory used by the old first link and then
		set the pointer back to NULL */
		free(tempLinkPtr);
		tempLinkPtr = 0;
	}

	/* END UPDATES */
}


int linkedListStackIsEmpty(struct linkedListStack *s) {

	/* Fix me */
	assert(s != 0);

	if (s->firstLink != 0) {	/* List is not empty */
		return 0;	/* false */
	}

	else {	/* List is empty */
		return 1;	/* true */
	}

	/* END UPDATES */

}

/**********************************************************************
                               main
**********************************************************************/
int main() 
{
	struct linkedListStack *s = 0;

	linkedListStackInit(&s);

	linkedListStackPush(&s, 1);
	linkedListStackPush(&s, 2);
	linkedListStackPush(&s, 3);

	printf("TOP VALUE: ");
	printf("%d", linkedListStackTop(&s));
	printf("\n\n");

	linkedListStackPop(&s);
	printf("TOP VALUE: ");
	printf("%d", linkedListStackTop(&s));
	printf("\n\n");

	linkedListStackPush(&s, 10);
	printf("TOP VALUE: ");
	printf("%d", linkedListStackTop(&s));
	printf("\n\n");

	linkedListStackPop(&s);
	linkedListStackPop(&s);
	linkedListStackPop(&s);
	linkedListStackPop(&s);

	linkedListStackFree(&s);


	return 0;
}
