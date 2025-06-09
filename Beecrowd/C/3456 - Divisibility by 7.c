#include <stdio.h>

int main(){

  long long n; scanf("%lld", &n);

  int rest;
  while(n > 9){
    printf("%lld\n", n);
    n = (n / 10) * 3 + (n % 10);
  }
   printf("%lld\n", n);

  return 0;
}
