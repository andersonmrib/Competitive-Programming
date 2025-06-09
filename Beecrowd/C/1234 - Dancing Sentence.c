#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  char str[51];
  while (gets(str) != NULL){
    int upperCase = 1;
    for (int i=0;i<strlen(str);i++){

        if (!isalpha(str[i])) continue;
        if (upperCase) str[i] = toupper(str[i]);
        else           str[i] = tolower(str[i]);
        upperCase = 1 - upperCase;
        }
      printf("%s\n", str);
      }
  return 0;
}