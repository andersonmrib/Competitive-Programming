#include <stdio.h>

int main(){

  unsigned int x, m;
  while(scanf("%u %u", &x, &m), (x || m)){
    long result = x*m;
    printf ("%ld\n", result);
  }

  return 0;
}
