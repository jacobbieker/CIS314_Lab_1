#include <stdio.h> /* Header File */

int main(void) {

  int  remainder, quotient;
  
  int binaryNumber[20000000000], i=1, j;
 
  printf("Enter a base-10 number to convert to binary")
  scanf("%d", &quotient);

  while (quotient != 0) {
  binaryNumber[i++] = quotient % 2;
  
  quotient = quotient / 2;
}
 
  printf("The Binary representation is: ");
 for (j = i - 1; j > 0; j--) {
    printf("%d", binaryNumber[j]);
   
} 

return 0;
}
