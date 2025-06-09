#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_sieze;
vll p;
bitset<10000010> bs;

void sieve(ll upperbound){
  _sieve_sieze = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(int i=2; i<_sieve_sieze; i++)
    if(bs[i]){
    for(int j=i*i; j<_sieve_sieze; j+=i)
      bs[j] = 0;
    p.push_back(i);
  }
}

bool isPrime(ll n){
  if(n < _sieve_sieze) return bs[n];
  for(int i=0; i<(int)p.size() && p[i]*p[i] <= n; i++)
    if(n%p[i] == 0) return false;
  return true;
}

int main(){

  speedBoost;
  sieve(pow(2, 15));

  int num;
  while((cin >> num), num){

    int ans = 0;
    for(int i=0; i<(int)p.size() && p[i] <= num/2; i++)
      if(isPrime(num-p[i])) ans++;

    cout << ans << "\n";
  }

  return 0;
}
