#include <stdio.h>
#include <stdlib.h>

int main(){

  char number[15];
  int base;
  while(1){
    scanf("%s", number);
    if(number[0] == '0' && number[1] == 'x') base = 16;
    else                                     base = 10;

    long int aux = strtol(number, NULL, base); //Uses strtol for converting a string into a number according to the base

    if(aux < 0)    break;
    if(base == 16) printf("%d\n", aux);
    else           printf("0x%lX\n", aux);
  }

  return 0;
}
