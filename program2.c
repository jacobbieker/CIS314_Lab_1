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

   int desired_number = 0;
   printf("Enter what number to find: ");
   scanf("%d", &desired_number);

   readInput(in_file, in_file_name, array, desired_number);

   return 0;
}

int readInput(FILE *input_file, char file_name[], int values[], int desired_number) {
	int count = 0;
	int value = 0;
	input_file = fopen(file_name, "r");
	if (feof(input_file) != 0)
	{
		printf("Error: can't open file to read\n");
	}
	else
	{
		printf("File opened successfully to read\n");
	}

	//Get the first line of the file, which gives the size of the array
	while (fscanf(input_file, "%d", &value) != EOF) {
		values[count] = value;
		count++;
	}
	fclose(input_file);

	int delta;
	clock_t t1, t2;
	t1 = clock();
	int recursive_result = recursiveBinarySearch(values, desired_number, 0, (sizeof(values) / sizeof(values[0])) - 1);
	t2 = clock();
	delta = t2 - t1;

	int delta1;
	clock_t t3, t4;
	t3 = clock();
	int iterative_result = iterativeBinarySearch(values, desired_number);
	t4 = clock();
	delta1 = t3 - t4;

	displayOutput(values, recursive_result, delta, delta1, iterative_result);

	return 0;
}
int recursiveBinarySearch(int list_of_numbers[], int desired_number, int low_number, int high_number) {
	int mid = (low_number + high_number) / 2;
	if (low_number > high_number)
	{
		return -1;
	}
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
		if (list_of_numbers[mid] < desired_number) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;
}

int displayOutput(int data_array[], int recursive_result, int recursive_time, int iterative_time, int iterative_result) {
	int array_size = (sizeof(data_array) / sizeof(data_array[0])) - 1;
	int j = 0;
	printf("The input array is: ");
	for (j = array_size; j > 0; j--) {
		printf("%d ", data_array[j]);
	}
	printf("\nRecursive result: %d, Time taken: %d", recursive_result, recursive_time);
	printf("\nIterative result: %d, Time taken: %d", iterative_result, recursive_time);

	return 0;
}