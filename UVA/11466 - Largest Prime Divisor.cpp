#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MAX 10000010
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
vll p;
ll _sieve_size;
bitset<MAX> bs;
// 10^7 is inside the square root of 10^14

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
  ll n;
  while((cin >> n), n){

    if(n < 0) n = n*-1;
    if(n <= MAX && bs[n]) cout << -1 << "\n";
    else{
      ll diffPF = 0;
      ll bigger = 0;
      ll cur = n;
      for(int i=0; i<p.size() && p[i] <= sqrt(n); i++){
        if(cur%p[i] == 0){
          diffPF++;
          bigger = p[i];
          while(cur%p[i] == 0) cur /= p[i];
        }
      }
      if(cur != 1){
        bigger = cur;
        diffPF++;
      }
      if(diffPF < 2) cout << -1 << "\n";
      else           cout << bigger << "\n";
    }
  }

  return 0;
}
