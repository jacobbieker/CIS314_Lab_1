/*
 * in_lab_dec_to_bin.c
 * Brian Gravelle
 * CIS 314 Lab 1
 * in lab project
 *
 */

 #include <stdio.h>

 //function headers
 int get_input();
 int convert_to_binary(int decimal, char *binary, int bit_sig);

 //input will be one decimal number to convert to binary
 int main(void) {

    int decimal, i;
    int bit_sig = 15;
    char binary[16];
    for(i = 0; i < 15; i++)
      binary[i] = '0';
    binary[bit_sig--] = '\0';

    printf("\n");

    decimal = get_input();
    convert_to_binary(decimal, binary, bit_sig);
    
    printf("The binary form of %d is %s\n\n", decimal, binary);

 	return 0;
 }

// This function prompts a user and accepts the input from them
// return: integer input by the user
int get_input() {
   int decimal;
   printf("Please enter an integer: ");
   scanf("%d", &decimal);
   return decimal;
}

// This function recursively converts a decimal number to binary
// Params: decimal is the decimal number, binary points to a char array
//         that will represent the binary value, bit_sig is the next
//         position in the array to be filled.
// Return: The function returns the next bit position to be filled.
// demonstrates passing an array
int convert_to_binary(int decimal, char *binary, int bit_sig){

    int quotient; 
    int remain;
    quotient = decimal / 2;
    remain   = decimal % 2;

    if (remain == 0) 
      binary[ bit_sig-- ] = '0';
    else 
      binary[ bit_sig-- ] = '1';

    if (quotient != 0)
      bit_sig = convert_to_binary(quotient, binary, bit_sig);

    return bit_sig;

 }
 