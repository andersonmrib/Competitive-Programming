#include <stdio.h>

int main(){

  int k; scanf("%d", &k);
  if      (k == 1)           printf("Top 1\n");
  else if (k > 1 && k < 4)   printf("Top 3\n");
  else if (k > 3 && k < 6)   printf("Top 5\n");
  else if (k > 5 && k < 11)  printf("Top 10\n");
  else if (k > 10 && k < 26) printf("Top 25\n");
  else if (k > 25 && k < 51) printf("Top 50\n");
  else                       printf("Top 100\n");

  return 0;
}
