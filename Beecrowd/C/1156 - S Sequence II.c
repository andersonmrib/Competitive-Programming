#include <stdio.h>

int main(){

 float sum = 0;
 for(int i=1, j=1; i<=39; i+=2, j*=2)
    sum += (float)i/j;

 printf("%.2f\n", sum);

  return 0;
}
