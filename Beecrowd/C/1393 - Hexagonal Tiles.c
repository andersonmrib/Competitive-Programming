#include <stdio.h>

int main() {

  int n;
  while(scanf("%d", &n), n){  // we can derive the result using Fibonacci's formula
    printf("%.0lf\n", (pow(((1 + sqrt(5))/2),n+1) - pow(((1 - sqrt(5))/2),n+1))/sqrt(5));
  }

  return 0;
}

/*                           // you can use the iterative version
int main() {                 // if you are not comfortable with the
                             // formula above
  int n;
  int fib[40];
  fib[1] = 1, fib[2] = 2;
  for(int i=3; i<=40; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
  while(scanf("%d", &n), n){
    printf("%d\n", fib[n]);

  }

  return 0;
}
*/
