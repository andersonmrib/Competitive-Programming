#include <stdio.h>

int main(){

  long long a, b;
  scanf("%lld %lld", &a, &b);
  printf("%lld\n", ((a+b)*(b-a+1))/2);

  return 0;
}
