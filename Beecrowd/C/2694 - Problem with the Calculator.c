#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

  int n; scanf("%d ", &n);
  while(n--){
    char *delimiters = "abcdefghijklmnopqrstuvwxyz"; //Creates all delimiters for strtok
    char str[15]; scanf("%s", str);
    int sum = 0;

    char *token = strtok(str, delimiters); //Splits the string in multiple strings with numbers

    while (token != NULL){

        sum += atoi(token); //Uses 'atoi' function for converting a string into a number
        token = strtok(NULL, delimiters); //Reach the next token
    }

    printf ("%d\n", sum);
  }

  return 0;
}
