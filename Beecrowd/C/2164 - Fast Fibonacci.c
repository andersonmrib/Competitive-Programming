#include <stdio.h>
#include <math.h>

double fib (int n);

int main() {

  int fibNumber; //Fibonacci number.

  scanf ("%d", &fibNumber);

  printf ("%.1lf\n", fib(fibNumber));

  return 0;
}

double fib (int n){

  double result;

  result = (pow(((1 + sqrt(5))/2),n) - pow(((1 - sqrt(5))/2),n))/sqrt(5);

  return result;

}
