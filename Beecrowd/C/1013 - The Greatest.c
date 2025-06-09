#include <stdio.h>

int main() {

  int a, b, c;

  scanf ("%d %d %d", &a, &b, &c);

  int Mab = (a + b + abs(a - b))/2; //Calculates the greatest integer between a and b;
  int M = (Mab + c + abs(Mab - c))/2; //Calculates the final greatest between c and the previous greatest.

  printf ("%d eh o maior\n", M);

  return 0;
}
