#include <stdio.h>
#include <stdlib.h>

int fib (int number);

int fibCalls (int number);

int calls = 0;

int main() {

  unsigned int n;
  unsigned int i;

  scanf ("%u", &n);

  int *ptr = (int*)malloc(n * sizeof(int));

  for (i=0;i<n;i++)
  {
      scanf ("%d", &ptr[i]);
  }

  for (i=0;i<n;i++)
  {
      calls = 0;
      printf ("fib(%d) = %d calls = %d\n", ptr[i], calls - 1, fib(ptr[i]));
  }

  free(ptr);
  
  return 0;
}

int fib (int number){

  if (number == 0 || number == 1)
  {
    calls++;
    return number;
  }
  else
  {
  calls++;
  return fib (number-1) + fib (number-2);
  }
}
