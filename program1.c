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

static char baseArray[MAX_NUM+1] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' }; //create the base Array with all the digits necessary
// Implement the rest of the program

int main(){

	char in_number[MAX_NUM+1];
	int in_base = 0;
	int out_base = 0;
	char out_number[MAX_NUM+1];

	printf("Enter a number for the base to convert from, between 2 and 16: ");
	scanf("%d", &in_base);
	
	printf("Enter a number for the base to be converted to, between 2 and 16: ");
	scanf("%d", &out_base);

	printf("Enter the number to be converted: ");
	scanf("%s", in_number);

	//Check input to see if outside the limits
	if (16 < in_base || in_base < 2 )
	{
		printf("Inputted base is too large.");
		return -1;
	}
	else if (16 < out_base || out_base < 2) {
		printf("Outputted base is too large.");
		return -1;
	}

	int decimalized_number = toDecimal(in_number, in_base);
	printf("\nThe decimal representation of %s is: %d \n", in_number, decimalized_number);

	int based_number = fromDecimal(decimalized_number, out_base);
	printf("\nThe base %d representation of the base %d number %s is: %s \n", in_base, out_base, in_number, out_number);

	return 0;
}

int toDecimal(char number[], int in_base) {
	int valuefound = 0;//used as boolean
	int decval;
	char *current = &number[0];
	int i;

	while (*current) {
		decval = decval * in_base;
		for (i = 0, valuefound = 0; i <= MAX_NUM; i++) {
			if (baseArray[i] == *current) {
				if (i < in_base) {
					decval += 1;
					valuefound = 1;
				}
				else {
					return -1;
				}
			} if (i == MAX_NUM && valuefound == 0) {
				return -1;
			}
		}
		++current;
	}
	return decval; // returns the correct decimal value
}

int fromDecimal(int number, int base) {
	int remainder;
	char outbaseArray[MAX_NUM+1], i = 1, j;

	while (number != 0)
	{
		remainder = number % base;
		outbaseArray[i++] = baseArray[remainder];

		number = number / base;
	}

	printf("The base %d representation of %d is: ", number, base);
	for (j = i - 1; j > 0; j--) {
		printf("%c", outbaseArray[j]);
	}

	return 0;
}