#include <stdio.h>

int main() {

 unsigned long long hashmat, enemy;

 while (scanf ("%llu %llu", &hashmat, &enemy) != EOF)
 {
     if (hashmat > enemy) printf ("%llu\n", hashmat - enemy);
     else                 printf ("%llu\n", enemy - hashmat);
 }

  return 0;
}
