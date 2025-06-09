#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

  int n, shifts; //Number of test cases and shifts.
  char phrase[51];
  int i, j;

  scanf ("%d", &n);

  for (i=0;i<n;i++)
  {
      scanf (" %[^\n]\n", &phrase);
      scanf ("%d", &shifts);

      for (j=0;j<strlen(phrase);j++) {
          phrase[j] = ((phrase[j] - 'A' - shifts + 26) % 26) + 'A'; // (x - y + N) mod N;
      }

      printf ("%s\n", phrase);
  }

  return 0;
}
