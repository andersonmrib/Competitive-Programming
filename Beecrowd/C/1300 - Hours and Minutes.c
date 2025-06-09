#include <stdio.h>

int main(){

  int a;
  while (scanf("%d", &a) != EOF)
    (a % 6 == 0) ? printf ("Y\n") : printf ("N\n");
  return 0;
}
