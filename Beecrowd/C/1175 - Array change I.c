#include <stdio.h>

int main(){

  int array[20];
  for (int i=0;i<20;i++)
    scanf("%d", &array[i]);
  for (int j=0;j<20;j++)
    printf ("N[%d] = %d\n", j, array[19-j]);

  return 0;
}
