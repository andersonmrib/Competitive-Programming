#include <stdio.h>

int main (){

  int arr[10];
  int number; scanf ("%d", &number);

  for (int i=0;i<10;i++)
  {
      if (i>0) arr[i] = 2*arr[i-1];
      else arr[i] = number;

      printf ("N[%d] = %d\n", i, arr[i]);
  }

  return 0;
}
