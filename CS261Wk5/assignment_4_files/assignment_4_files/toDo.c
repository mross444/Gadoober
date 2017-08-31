/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    //const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
  
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	if (command == 'l') {		// load

		/* get the filename from the user */
		printf("Please enter the filename: ");
		
		char filename[FORMAT_LENGTH];
		int i;

		/* reference: http://www.java2s.com/Code/C/Console/Usefgetstoreadstringfromstandardinput.htm
		reading string from console using fgets */

		/* use fgets to read the line */
		fgets(filename, TASK_NAME_SIZE, stdin);

		/* remove newline */
		i = strlen(filename) - 1;
		if (filename[i] == '\n')
			filename[i] = '\0';

		/* referece - https://www.tutorialspoint.com/cprogramming/c_file_io.htm 
		working with files */
		
		/* attempt to open the file */
		FILE * fp;
		fp = fopen(filename, "r" );

		/* display error if file did not exist */
		if (fp == 0) {
			printf("File does not exit.  Load failed.\n\n");
		}

		/* otherwise, call the listLoad function */
		else {
			listLoad(list, fp);
			fclose(fp);
			printf("The list has been loaded from file successfully.\n\n");
		}

		/* set pointer back to null */
		fp = 0;
	}

	else if (command == 's') {		// save
		
		/* get the filename from the user */
		printf("Please enter the filename: ");

		char filename[FORMAT_LENGTH];
		int i;

		/* reference: http://www.java2s.com/Code/C/Console/Usefgetstoreadstringfromstandardinput.htm
		reading string from console using fgets */

		/* use fgets to read the line */
		fgets(filename, TASK_NAME_SIZE, stdin);

		/* remove newline */
		i = strlen(filename) - 1;
		if (filename[i] == '\n')
			filename[i] = '\0';

		/* referece - https://www.tutorialspoint.com/cprogramming/c_file_io.htm
		working with files */

		FILE * fp = fopen(filename, "w");
		listSave(list, fp);
		fclose(fp);

		printf("The list has been saved into the file successfully.\n\n");
	}

	else if (command == 'a') {		// add

		char newTaskName[TASK_NAME_SIZE];
		int newTaskPriority;
		int i;

		printf("Please enter the task description: ");
		
		/* reference: http://www.java2s.com/Code/C/Console/Usefgetstoreadstringfromstandardinput.htm
		reading string from console using fgets */
		
		/* use fgets to read the line */
		fgets(newTaskName, TASK_NAME_SIZE, stdin);

		/* remove newline */
		i = strlen(newTaskName) - 1;
		if (newTaskName[i] == '\n')
			newTaskName[i] = '\0';

		printf("Please enter the task priority (0-999): ");
		
		/* reference: https://stackoverflow.com/a/26583787 reading integer value from console */

		char *end;
		char buf[4056];

		do {
			if (!fgets(buf, sizeof buf, stdin))
				break;

			// remove \n
			buf[strlen(buf) - 1] = 0;

			/* convert the entry to int using strtol */
			newTaskPriority = strtol(buf, &end, 10);
		} while (end != buf + strlen(buf));

		/* create the task using the user entered name and priority */
		Task * newTask = taskNew(newTaskPriority, newTaskName);

		/* add the task to the heap */
		dyHeapAdd(list, newTask, taskCompare);

		printf("The task '%s' (PRIORITY %d) has been added to your to-do list.\n\n", newTaskName, newTaskPriority);
	}

	else if (command == 'g') {
		
		/* check if list is empty */
		if (dySize(list) == 0) {
			printf("Your to-do list is empty!\n\n");
		}

		/* otherwise, print the name of the first task */
		else {

			/* get the name of the first task */
			Task * tmpTsk = dyHeapGetMin(list);
			char tmpTskNm[TASK_NAME_SIZE];
			strcpy(tmpTskNm, tmpTsk->name);

			/* display result */
			printf("Your first task is: %s\n\n", tmpTskNm);

			/* set pointer back to null */
			tmpTsk = 0;
		}

	}

	else if (command == 'r') {

		/* check if list is empty */
		if (dySize(list) == 0) {
			printf("Your to-do list is empty!\n\n");
		}

		/* otherwise, print the name of the first task */
		else {
			
			/* get the name of the first task */
			Task * tmpTsk = dyHeapGetMin(list);
			char tmpTskNm[TASK_NAME_SIZE];
			strcpy(tmpTskNm, tmpTsk->name);

			/* remove the task */
			taskDelete(tmpTsk);
			dyHeapRemoveMin(list, taskCompare);

			/* display result */
			printf("Your first task '%s' has been removed from the list.\n\n", tmpTskNm);

			/* set pointer back to null */
			tmpTsk = 0;
		}

	}

	else if (command == 'p') {

		/* check if list is empty */
		if (dySize(list) == 0) {
			printf("Your to-do list is empty!\n\n");
		}

		/* otherwise, loop through the tasks and print the names */
		else {

			/* iterate through the array and display name of eash task */
			Task * tmpTsk = dyHeapGetMin(list);
			char tmpTskNm[TASK_NAME_SIZE];

			int i;

			for (i = 0; i < dySize(list); i++) {
				tmpTsk = dyGet(list, i);
				strcpy(tmpTskNm, tmpTsk->name);
				printf("%s\n\n", tmpTskNm);
			}

			/* set pointer back to null */
			tmpTsk = 0;
		}

	}

	else if (command == 'e') {
		printf("Bye!\n\n");
	}

	else {
		printf("Invalid menu choice, please try again.\n\n");
	}
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

	/* loop through remaining tasks and delete them */
	int i;
	Task* tmpTsk;

	for (i = 0; i < dySize(list); i++) {
		tmpTsk = dyGet(list, i);
		taskDelete(tmpTsk);
	}

	tmpTsk = 0;

    dyDelete(list);
	list = 0;


    return 0;
}