#include <stdio.h>
#include <stdlib.h>

int especialSort(const void *x, const void *y){
  int a = *((int*)x);
  int b = *((int*)y);

  if      (a%2 == 0 && b%2 == 0) return a - b; //Even and even
  else if (a%2 == 0 && b%2 == 1) return -1;    //Odd and even
  else if (a%2 == 1 && b%2 == 1) return b - a; //Odd and odd
  else                           return 1;     //Even and odd
}

int main(){

  int n; scanf("%d", &n);
  int vec[n];

  for(int i=0; i<n; i++) scanf("%d", &vec[i]);
  qsort(vec, n, sizeof(int), especialSort);
  for(int i=0; i<n; i++) printf("%d\n", vec[i]);

  return 0;
}
