#include <stdio.h>

int main() {

  int a, n;
  unsigned short int i;
  int index = 0;

  scanf ("%d %d", &a, &n);

  while (n == 0 || n < 0) scanf ("%d", &n);

  for (i=0;i<n;i++) //Makes the count of the difference between every a+i number. E.g: 5 3 = 5+0 + 5+1 = 5+2
      index += i;

      printf ("%d\n", a*n + index);

  return 0;
}
