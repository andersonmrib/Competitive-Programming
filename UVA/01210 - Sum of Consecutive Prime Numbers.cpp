#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MAX 100010
using namespace std;

typedef long long ll;
ll _sieve_size;

typedef vector<ll> vll;
vll p;
bitset<MAX> bs;

void sieve(ll upperbound){
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<_sieve_size; i++)
    if(bs[i]){
    for(ll j=i*i; j<_sieve_size; j+=i)
      bs[j] = 0;
    p.push_back(i);
  }
}

int main(){

  speedBoost;
  sieve(MAX);

  ll ways[MAX];
  for(ll i=0; i<p.size(); i++){
    ll sum = 0;
    for(ll j=i; j<p.size(); j++){
      sum += p[j];
      if(sum >= MAX) break;
      else ways[sum]++;
    }
  }

  int n;
  while((cin >> n), n)
    cout << ways[n] << "\n";

  return 0;
}
