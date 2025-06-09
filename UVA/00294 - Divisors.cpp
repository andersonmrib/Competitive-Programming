#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
ll _sieze_size;
vll p;
bitset<10000010> bs;

void sieve(ll upperbound){
  _sieze_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<_sieze_size; i++)
    if(bs[i]){
      for(ll j=i*i; j<_sieze_size; j+=i)
        bs[j] = 0;
      p.push_back(i);
    }
}

int numDiv(ll N){
  int ans = 1;
  for(int i=0; (i<(int)p.size()) && (p[i]*p[i] <= N); i++){
    int power = 0;
    while(N%p[i] == 0) { N /= p[i]; power++; }
    ans *= power+1;
  }
  return (N != 1) ? 2*ans : ans;
}

int main(){

  speedBoost;
  sieve(10000000);

  int t; cin >> t;
  while(t--){
    ll L, U; cin >> L >> U;

    int ans = 0, number;
    for(ll i=L; i<=U; i++){
      ll divisors = numDiv(i);
      if(ans < divisors){
        ans = divisors;
        number = i;
      }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, number, ans);
  }

  return 0;
}
