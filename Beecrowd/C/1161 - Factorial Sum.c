#include <stdio.h>

unsigned long long int factorial (int n); //Prototype function

int main () {

  int n, m;
  unsigned long long int v1, v2; // Values of factorial 

  while ( scanf ("%d %d", &n, &m) != EOF)
  {

    v1 = factorial(n);
    v2 = factorial(m);
    printf ("%llu\n", v1+v2);
  }

  return 0;
}

unsigned long long int factorial (int n) {

  int i;
  unsigned long long  int f1=1;

  for (i=1;i<=n;i++)
  {
    f1*=i;
  }

    return f1;
}