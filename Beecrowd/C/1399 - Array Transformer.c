#include <stdio.h>
typedef long long ll;

int main(){


  ll n, m, u; scanf("%lld %lld %lld", &n, &m, &u);
  ll L, R, v, p;
  ll k; //Range between L and R
  ll vector[n+1]; //I preferred to use a vector ignoring index 0, since it is going to be easier to get k

  for(int i=1; i<n+1; i++) scanf("%lld", &vector[i]);

  while(m--){

    k = 0;
    scanf("%lld %lld %lld %lld", &L, &R, &v, &p);

    for(int i=L; i<=R; i++)
      if(vector[i] < v) k++;

    vector[p] = u*k/(R - L + 1);
  }

  for(int i=1; i<n+1; i++) printf("%lld\n", vector[i]);

  return 0;
}
