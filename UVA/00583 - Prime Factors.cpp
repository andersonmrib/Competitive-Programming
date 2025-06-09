#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_sieze;
vll p;
bitset <10000010>bs;

void sieve(ll upperbound){
  _sieve_sieze = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<_sieve_sieze; i++)
    if(bs[i]){
      for(ll j=i*i; j<_sieve_sieze; j+=i)
        bs[j] = 0;
      p.push_back(i);
    }
}

vll getPrimeFactors(ll u){
  vll factors;
  for(int i=0; i<(int)p.size() && p[i]*p[i] <= u; i++)
    while(u%p[i] == 0){
      u /= p[i];
      factors.push_back(p[i]);
    }
    if(u != 1) factors.push_back(u);
  return factors;
}

int main(){

  speedBoost;
  sieve(10000000);

  ll num;
  while((cin >> num), num){

    bool isNegative = false;
    if(num < 0) isNegative = true;

    vll ans = getPrimeFactors(abs(num));

    printf("%lld = ", num);

    if(isNegative){
      printf("-1");
      if(!ans.empty())
        printf(" x ");
    }

    for(int i=0; i<ans.size(); i++){
      if(i > 0) printf(" x ");
      printf("%lld", ans[i]);
    }
    printf("\n");
  }

  return 0;
}
