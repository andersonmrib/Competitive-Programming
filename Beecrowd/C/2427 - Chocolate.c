#include <stdio.h>
#include <math.h>

int main(){

  float l; scanf("%f", &l);
  long long ans = 1;


  while(l >= 2){
    ans = ans*4 ;
    l /= 2;
  }
  printf("%lld\n", ans);

  return 0;
}
