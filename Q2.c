/*********************************************************************
** Program Filename: Q2.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  Program that demonstrates using pointers in c and 
		passing integer values by reference to a function.
** Input:  none
** Output:  console
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c);

/**********************************************************************
								foo
	Takes three integer variables as inputs with the first two being
	passed by reference.  Doubles the value of the first variable 
	and halves the value of the second variable.  Returns the sum
	of the first two variables.			
**********************************************************************/
int foo(int* a, int* b, int c) {
	/*Set a to double its original value*/
	*a = 2 * (*a);

	/*Set b to half its original value*/
	*b = (*b) / 2;

	/*Assign a+b to c*/
	c = (*a) + (*b);

	/*Return c*/
	return c;
}

/**********************************************************************
								main			
**********************************************************************/
int main(void) {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x, y, z;
	x = 5;
	y = 6;
	z = 7;

	/*Print the values of x, y and z*/
	printf("x: ");
	printf("%d", x);
	printf("\ny: ");
	printf("%d", y);
	printf("\nz: ");
	printf("%d", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	printf("\n\nCalling foo...\n\n");
	printf("foo returned: ");

	/*Print the value returned by foo*/
	printf("%d", foo(&x, &y, z));

	/*Print the values of x, y and z again*/
	printf("\n\nx: ");
	printf("%d", x);
	printf("\ny: ");
	printf("%d", y);
	printf("\nz: ");
	printf("%d", z);

	printf("\n\n");

	/*Is the return value different than the value of z?  Why?*/
	/*The return value is different since z is not being passed by reference.
	foo uses a local int variable c and returns it, though this does not
	affect the variable z used in the main function.*/

	return 0;
}