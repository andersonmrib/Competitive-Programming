#include <stdio.h>

int main () {

  int i, n;
  scanf ("%d", &n);

  for (i=1;i<n+1;i+=2)
    printf ("%d\n", i);

  return 0;
}
