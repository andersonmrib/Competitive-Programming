#include <stdio.h>

int main(){

  unsigned int a, b;
  while(scanf("%u %u", &a, &b) != EOF){
    int t = a^b;
    printf("%u\n", t);
  }

  return 0;
}
