#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  unsigned short int n; //Number of test cases.
  unsigned short int i;
  double result;

  scanf ("%d", &n);

  for (i=0;i<n;i++)
  {
      unsigned short int x; //Number of squares to be used.

      scanf ("%d", &x);

      result = pow(2,x);

      printf ("%.lf kg\n", trunc(result/12000));
  }

  return 0;
}
