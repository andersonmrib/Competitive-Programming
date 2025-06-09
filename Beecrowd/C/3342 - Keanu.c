#include <stdio.h>

int main(){

  int n; scanf ("%d", &n);
  int sum = 0;

  if (n%2 == 0)
    printf ("%d casas brancas e %d casas pretas\n", n*n/2, n*n/2);
  else
    {
    for (int i=n;i>1;i--)
        if (i%2 == 0) sum += i;

    printf ("%d casas brancas e %d casas pretas\n",1+sum*2 ,sum*2);
    }

  return 0;
}
