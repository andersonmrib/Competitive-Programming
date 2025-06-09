#include <stdio.h>

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int Nth; //Fibonacci number.
    unsigned long long fib[61];

    fib[0] = 0, fib[1] = 1;
    for (int i=2;i<=60;i++)
        fib[i] = fib[i-1] + fib[i-2];

    scanf("%d", &Nth);
    printf ("Fib(%d) = %lld\n", Nth, fib[Nth]);
  }

  return 0;
}
