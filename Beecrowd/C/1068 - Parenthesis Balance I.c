#include <stdio.h>
#include <string.h>

int main(){

  char expression[1001];
  int parenthesis;
  int i;

  while(scanf("%s", expression) != EOF){
    parenthesis = 0;
    int len = strlen(expression);

    for(i=0;i<len; i++){
      if(expression[i] =='(') parenthesis++;
      else if(expression[i] == ')')
      {
          if(parenthesis > 0) parenthesis--;
          else break;
      }
    }

    if (!parenthesis && i == len) printf("correct\n"); //Checks if the parenthesis are balanced and all the string has been read in case we find a ')' befofe '('
    else                          printf("incorrect\n");
  }


  return 0;
}
