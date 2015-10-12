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

static char baseArray[MAX_NUM] = { 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F }; //create the base Array with all the digits necessary
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

int toDigits(int number, int base) {
// Convert from a number to a specific base
	int digits[MAX_DECIMAL], i = 1, j;
		while (number > 0) {
			digits[i++] = number % base;
			number = number / base;
			return digits;
		}
	
}

int fromDigits(int digits, int base) {
	// Convert from an array of digits to a specific base
	int number = 0;
	for 
}