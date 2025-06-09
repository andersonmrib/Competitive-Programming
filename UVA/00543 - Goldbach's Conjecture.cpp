#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
vll p;
ll _sieve_size;
bitset<10000010> bs;

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

bool isPrime(ll n){
  if(n < _sieve_size) return bs[n];
  for(int i=0; i<(int)p.size() && p[i]*p[i] <= n; i++)
    if(n%p[i] == 0) return false;
  return true;
}

int main(){

  speedBoost;

  sieve(1000000);

  int num;
  while((cin >> num), num){


    bool hasSolution = false;
    for(int i=0; i<p.size(); i++){
      if(p[i] <= num - p[i] && isPrime(num - p[i])){
        hasSolution = true;
        printf("%d = %d + %d\n", num, p[i], num-p[i]);
        break;
      }
    }

    if(!hasSolution)
      printf("Goldbach's conjecture is wrong.\n");
  }

  return 0;
}
