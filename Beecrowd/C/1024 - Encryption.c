#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int n; scanf("%d", &n);
  getchar();

  while(n--){
    char message[1100]; fgets(message, 1100, stdin);
    char messageRev[1100];
    int len = strlen(message);

    if (message[len - 1] == '\n') //Careful with PE
        message[len - 1] = '\0';  //Removing this part will make extra line in your code
        len--; //'\0' does not count as part of the string's length

    for(int i=0; i<len; i++) //Makes the shifting to the right
    {
        if (isalpha(message[i]))
        message[i] = message[i] + 3;
    }

    for (int i=0; i<len; i++) //Getting the reversed string form
       messageRev[i] = message[len - 1 - i];
       messageRev[len] = '\0';

    strcpy(message, messageRev); //Copying the string reversed

    if (len%2 == 1) //Checks if the length is odd
    {
       for(int i=len/2; i<len; i++)
       message[i] = message[i] - 1;
    }
    else //If it's not odd, then it's even
    {
       for(int i=len/2; i<len; i++)
       message[i] = message[i] - 1;
    }
    printf("%s\n", message);
  }

  return 0;
}
