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

static char baseArray[MAX_NUM] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' }; //create the base Array with all the digits necessary
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
	scanf("%s", &in_number);

	while (quotient != 0)
	{
		int digitLoc = quotient % out_base;
		numberRemainder[i++] = baseArray[digitLoc];

		quotient = quotient / out_base;
	}

	printf("The base %d representation of the base %d number %s is: %s", &in_base, &out_base, &in_number, &out_number);

	return 0;
}

int toDecimal(char number[]) {
	int remainder;
	int decimalArray[MAX_DECIMAL], i = 1, j;

	int l;
	int array_size = (sizeof(number) / sizeof(number[0])) - 1;
	// For loop converts each char to its decimal int representation
	for (l = 0; l < array_size; l++)
	{
		int single_digit = 0;
		if (number[i] == 'A') {
			single_digit = 10;
		}
		else if (number[i] == 'B') {
			single_digit = 11;
		}
		else if (number[i] == 'C') {
			single_digit = 12;
		}
		else if (number[i] == 'D') {
			single_digit = 13;
		}
		else if (number[i] == 'E') {
			single_digit = 14;
		}
		else if (number[i] == 'F')
		{
			single_digit = 15;
		}
		else {
			single_digit = number[i] - '0'; //converts from char to int
		}
		decimalArray[l];//have to reverse this when reading it out
	}

	int decimal_array_size = (sizeof(decimalArray) / sizeof(decimalArray[0])) - 1;
	int number_to_decimal = 0;
	for (i = 0; i < decimal_array_size; i++) {
		
	}
	while (number != 0) {
		remainder = number % 10;
		decimalArray[i++] = remainder;

		number = number / 10;
	}
	//Loop through to create one number out of the array
	int decimalized_number;
	for (j = 0; j < decimal_array_size; j++) {
		int temp_num = decimalArray[j];
		int exponential_value = decimal_array_size - j;
		int k;
		for ( k = i; k > 0; k--)
		{
			temp_num *= 10; //Moves the digit to the correct spot
		}
		decimalized_number += temp_num;
	}

	printf("The decimal representation of %s is: %d", &number, &decimalized_number);
	return decimalized_number;
}

int fromDecimal(int number, int base) {
	int remainder;
	int decimalArray[MAX_DECIMAL], i = 1, j;

	while (number != 0)
	{
		remainder = number % base;
		decimalArray[i++] = baseArray[remainder];

		number = number / base;
	}

	printf("The base %d representation of %d is: ", &base, &number);
	for (j = i - 1; j > 0; j--) {
		printf("%d", decimalArray[j]);

	}

	return 0;
}