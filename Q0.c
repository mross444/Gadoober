/*********************************************************************
** Program Filename: Q0.c
** Author:  Michael Ross
** Date:  7/10/17
** Description: Declares an integer value, then uses a function (fooA)
		that prints out memory addresses and values related to the 
		declared integer.
** Input:  none
** Output:  console
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr);	/* prototype */

/**********************************************************************
								fooA
	Takes a pointer to an integer, then prints out the value pointed
	to, the memory address of the value pointed to, and the address
	of the pointer itself.			
**********************************************************************/
void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/
	printf("Value pointed to by iptr: ");
	printf("%d", *iptr);
	printf("\n");

	/*Print the address pointed to by iptr*/
	printf("Address pointed to by iptr: ");
	printf("%p", &(*iptr));
	printf("\n");


	/*Print the address of iptr itself*/
	printf("Address of iptr itself: ");
	printf("%p", &iptr);
	printf("\n");
}

/**********************************************************************
								main			
**********************************************************************/
int main() {
	/*declare an integer x*/
	int x = 4;		

	/*print the address of x*/
	printf("Address of x: ");   
	printf("%p", &x);
	printf("\n");

	/*Call fooA() with the address of x*/	
	fooA(&x);

	/*print the value of x*/
	printf("Value of x: ");   
	printf("%d", x);
	printf("\n");

	return 0;
}