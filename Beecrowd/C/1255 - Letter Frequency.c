#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  char sequence[201];
  int frequency[26];
  int mostFrequent;
  int n; scanf("%d", &n);
  getchar();

  while(n--){
    mostFrequent = 0;
    memset(frequency, 0, sizeof(frequency)); //Sets all the array values for 0

    scanf("%[^\n]", &sequence);
    getchar();

    for(int j=0; j<strlen(sequence); j++)
        if(isalpha(sequence[j])) frequency[tolower(sequence[j]) - 'a']++; //Increment every position of the array, obtaining the frequency of each letter

    for(int j=0; j<26; j++)
        if(mostFrequent < frequency[j]) mostFrequent = frequency[j]; //Gets the most frequent letter

    for(int j=0; j<26; j++)
        if(frequency[j] == mostFrequent) printf("%c", j + 'a'); //Print all the characters with the same frequency (bigger array value)

    printf("\n");
  }

  return 0;
}
