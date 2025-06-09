#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  char sequence[6000];
  char *words;

  while(scanf("%[^\n]%*c", sequence) != EOF)
  {
      char dummy = '\0';
      int alliteration = 0;
      int result = 0;

      words = strtok(sequence, " "); //Gets the first word of the sequence
      while(words != NULL)
      {
        char firstLetter = tolower(words[0]);

        if(firstLetter == dummy)
        {
            if(!alliteration) result++; //Same as `if(alliteration == 0)`
            alliteration = 1; //Marks when the alliteration starts
        }
        else alliteration = 0;

        dummy = firstLetter;

        words = strtok(NULL, " "); //Moves to the next word in the sequence, and the next, and the next...
      }
      printf("%d\n", result);
  }

  return 0;
}
