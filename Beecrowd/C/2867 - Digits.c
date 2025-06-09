#include <stdio.h>
#include <math.h>

int main(){

  int c; scanf("%d", &c);
  while(c--){
    int n, m; scanf("%d %d", &n, &m);
    printf("%d\n", (int)(m*log10(n)) + 1); //Use log10(n) + 1 for getting the number of digits of n
  }

  return 0;
}
