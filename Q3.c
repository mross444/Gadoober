/*********************************************************************
** Program Filename: Q3.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  Program that demonstrates the insertion sort and
		passing an array to a function.
** Input:  none
** Output:  console
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* numbers, int n);		/* prototype */

/**********************************************************************
								sort
	Performs an instertion sort on array numbers of size n			
**********************************************************************/
void sort(int* numbers, int n) {
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = numbers[i];
		j = i - 1;
		while (j >= 0 && numbers[j] > key)
		{
			numbers[j + 1] = numbers[j];
			j = j - 1;
		}
		numbers[j + 1] = key;
	}
}


/**********************************************************************
								main			
**********************************************************************/
int main() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;

	/*Allocate memory for an array of n integers using malloc.*/
	int *myNumbers = malloc(n * sizeof(int));

	/*Fill this array with random numbers, using rand().*/
	int i;
	for (i = 0; i < n; i++) {
		myNumbers[i] = 1 + rand() % 99;
		printf("%d", myNumbers[i]);
		printf("\n");	 /*Print the contents of the array.*/
	}

	/*Pass this array along with n to the sort() function of part a.*/
	printf("\n\nCalling sort...\n\n");
	sort(myNumbers, n);

	/*Print the contents of the array.*/
	for (i = 0; i < n; i++) {
		printf("%d", myNumbers[i]);
		printf("\n");
	}

	free(myNumbers);

	printf("\n\n");

	return 0;
}