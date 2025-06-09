#include <stdio.h>

int main() {

  int x, y;
  int bigger, smallest;
  int i;

  scanf ("%d %d", &x, &y);

  if (x > y) bigger = x, smallest = y;
  else       bigger = y, smallest = x;

  for (i=smallest+1; i>smallest && i <bigger;i++)
  {
     if (i%5 == 2 || i%5 == 3)
        printf ("%d\n", i);
  }

  return 0;
}
