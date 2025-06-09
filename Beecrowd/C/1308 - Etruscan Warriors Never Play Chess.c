#include <stdio.h>
#include <math.h>
typedef long long ll;

int main(){

  int TC; scanf("%d", &TC);
  while(TC--){
    ll N; scanf("%lld", &N);

    printf("%lld\n", (ll)(-1 + sqrt(1 + 8*N))/2);
  }

  return 0;
}

/*

   derive the formula using Arithmetic progression
   Sum(K) = k(k+1)/2
   N = k(k+1)/2, where N is the number of warriors
   2N >= k(k+1)
   2N >= k^2 + 1

   just solve this quadratic equation
   and you'll get your final expression

   (-1 + sqrt(1 + 8N))/2

*/
