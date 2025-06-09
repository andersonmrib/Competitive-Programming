#include <stdio.h>
#include <math.h>

int main () {

  int n;
  int i;

  scanf ("%d", &n);

  for (i=1;i<n+1;i++)
  {
      printf ("%d %d %d\n", i, i*i, i*i*i);
      printf ("%d %d %d\n", i, i*i+1, i*i*i+1);
  }
  return 0;
}
