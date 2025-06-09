#include <stdio.h>

int main () {

  int N;
  int h, m, s; //Hours, minutes and seconds.

  scanf ("%d", &N);

  h = N / 3600;
  m = (N - (3600 * h))/60;
  s = N % 60;

  printf ("%d:%d:%d\n", h, m, s);

  return 0;
}
