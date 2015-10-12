/*
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 * 
 * This program converts a x base to y base converter [less than 16]. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM 16
#define MAX_DECIMAL 2147483647 //for int

// Implement the rest of the program

int main(){

	char in_number[MAX_NUM+1];
	int in_base = 0;
	int out_base = 0;
	char out_number[MAX_NUM+1];

	int remainder, quotient;

	int numberRemainder[MAX_DECIMAL], i = 1, j;

	printf("Enter a number for the base to convert from, between 2 and 16");
	scanf("%d", &in_base);
	
	printf("Enter a number for the base to be converted to, between 2 and 16");
	scanf("%d", &out_base);

	printf("Enter the number to be converted");
	scanf("%d", &in_number);

	while (quotient != 0)
	{
		numberRemainder[i++] = quotient % out_base;

		quotient = quotient / out_base;
	}

	printf("The base %s representation of the base %s number %d is: %d", &in_base, &out_base, &in_number, &out_number);

	return 0;
}
