#define _CRT_SECURE_NO_WARNINGS		/* allow Visual Studio to use scanf */

/*********************************************************************
** Program Filename: Q5.c
** Author:  Michael Ross
** Date:  7/10/17
** Description: A program that propmts user to enter a word via the 
		console, then converts the word to "sticky" format and
		displays the result.
** Input: console
** Output:  console
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char);		/* prototypes */
char toLowerCase(char);
void sticky(char*);

/**********************************************************************
							 toUpperCase		
	Converts ch to lower case, assuming it is in upper case currently	
**********************************************************************/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/**********************************************************************
							 toLowerCase		
	Converts ch to lower case, assuming it is in upper case currently	
**********************************************************************/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/**********************************************************************
								sticky
	Takes a string as an input, then converts the string so that the 
	letters alternate between uppercase and lowercase, starting with 
	the first character as uppercase.			
**********************************************************************/
void sticky(char* word){
	int i = 0;
	int flag = 1;

	// Loop through each character in string until end is reached
	while (word[i] != '\0') {
		if (flag == 1) {		
			if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] = toUpperCase(word[i]);
			}
			flag = 0;
		}
		else {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				word[i] = toLowerCase(word[i]);
			}
			flag = 1;
		}
		i++;
	}
}

/**********************************************************************
								main			
**********************************************************************/
int main(){
	char str[100];

	printf("Enter a word to convert to sticky: ");

    /*Read word from the keyboard using scanf*/
	scanf("%s", &str);
    
    /*Call sticky*/
	sticky(str);
    
    /*Print the new word*/
	printf("\nNew word is: ");
	printf("%s", str);

	printf("\n\n");

    return 0;
}