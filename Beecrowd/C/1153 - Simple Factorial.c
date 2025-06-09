#include <stdio.h>

long long int factorial(int num){
    long long int f = 1;
    for(int i=1; i<=num; i++)
        f *= i;
    return f;
}

int main() {

  int n; scanf("%d", &n);
  printf("%lld\n", factorial(n));
    return 0;
}
