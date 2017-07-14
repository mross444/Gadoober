#ifndef __TYPE
#define __TYPE
# define TYPE int
# define TYPE_SIZE sizeof(int)
# endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct link {
   TYPE value;
   struct link * next;
};

struct listQueue {
   struct link *firstLink;
   struct link *lastLink;
};

void listQueueInit (struct listQueue *q) {
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0); /* lnk is the sentinel */
   lnk->next = 0;
   q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack (struct listQueue *q, TYPE e) {




}

TYPE listQueueFront (struct listQueue *q) {





}


void listQueueRemoveFront (struct listQueue *q) {








}

int listQueueIsEmpty (struct listQueue *q) {




}
