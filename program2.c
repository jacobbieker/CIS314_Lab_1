/*
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 *
 * This program reads a sorted array from a file and finds a requested number
 *    using recursive or iterative binary search. The array is read from a file
 *    defined by FILE_NAME, which should be written as the number of elements
 *    followed by the elements themselses. each number can be deliniated with
 *    any whitepace character. Also, the maximum size of the array is defined 
 *    as MAX_SIZE.
 * 
 * NOTE: The array must be sorted!!
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 150
#define FILE_NAME "array.dat" //must include quotes

// Implement the rest of the program

int main(void) {

   FILE *in_file;
   int array[MAX_SIZE];
   int size;
   char in_file_name[] = FILE_NAME;

   printf("\n\n=== CIS314 Fall 2014 - Lab 1: Part 2: Program 2 ===\n\n");


   printf("\n\n");

   return 0;
}

int recursiveBinarySearch(int list_of_numbers[], int desired_number, int low_number, int high_number) {
	if (low_number > high_number)
	{
		return -1;
	}
	int mid = (low_number + high_number)/2
	else if (list_of_numbers[mid] == desired_number)
	{
		return mid;
	}
	else if (list_of_numbers[mid] < desired_number)
	{
		return recursiveBinarySearch(list_of_numbers, desired_number, mid + 1, high_number);
	}
	else
	{
		return recursiveBinarySearch(list_of_numbers, desired_number, low_number, mid - 1);
	}

}

int iterativeBinarySearch(int list_of_numbers[], int desired_number) {
	int low = 0;
	int high = (sizeof(list_of_numbers) / sizeof(list_of_numbers[0])) - 1;

	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (mid == desired_number)
		{
			return mid;
		}
		else if (list_of_numbers[mid] < desired_number) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;
}
