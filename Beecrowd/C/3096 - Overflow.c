#include <stdio.h>
#include <math.h>

int main(){

  int n; scanf("%d", &n);
  int stirling = trunc(n*log10(n/exp(1)) + log10(2*3.14159*n)/2.0) + 1;
  printf("%d\n", stirling);

  return 0;
}
