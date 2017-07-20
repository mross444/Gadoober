/*********************************************************************
** Program Filename: stackapp.c
** Author:  Michael Ross
** Date:  7/17/17
** Description: Adds in nextChar and isBalanced functions to existing
		definitions from dynamicArray.c
** Input:  none
** Output:  console
*********************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* validate s is not null */
	assert(s != 0);

	DynArr *dyn;
	dyn = newDynArr(10);

	TYPE checkVal = nextChar(s);

	while (checkVal != '\0') {

		printf("\nchecking char: ");
		printf("%c", checkVal);

		/* Add left sided expressions to the top of the stack */
		if (checkVal == '(' || checkVal == '{' || checkVal == '[') {
			pushDynArr(dyn, checkVal);
		}

		if (checkVal == ')' || checkVal == '}' || checkVal == ']') {

			/* return false if array is empty */
			if (isEmptyDynArr(dyn)) {
				deleteDynArr(dyn);
				return 0;
			}

			/* return false is right sided expression does not match
			value at the top of the stack*/
			if (checkVal == ')' && topDynArr(dyn) != '(') {
				deleteDynArr(dyn);
				return 0;
			}

			if (checkVal == '}' && topDynArr(dyn) != '{') {
				deleteDynArr(dyn);
				return 0;
			}

			if (checkVal == ']' && topDynArr(dyn) != '[') {
				deleteDynArr(dyn);
				return 0;
			}

			/* remove the top value */
			popDynArr(dyn);
		}

		checkVal = nextChar(s);
	}

	/* check if anything is left in the stack, if so return false */
	if (!isEmptyDynArr(dyn)) {
		deleteDynArr(dyn);
		return 0;
	}

	/* reached the end without finding problems - return true*/
	deleteDynArr(dyn);

	return 1;
}


int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res == 1)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

