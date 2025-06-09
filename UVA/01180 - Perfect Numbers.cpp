#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MAX 10000010
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

bool isPrime(ll n){
  if(n < _sieve_size) return bs[n];
  for(ll i=0; (i<_sieve_size) && (p[i]*p[i] <= n); i++)
    if(n%p[i] == 0) return false;
  return true;
}

int main(){

  speedBoost;
  sieve(MAX);
  int n; cin >> n; cin.ignore();
  string str; getline(cin, str);

  stringstream ss(str);
  string data;
  while(getline(ss, data, ',')){
    ll number = stoi(data);
    ll check = (ll)pow(2, number) - 1;
    if(isPrime(number) && isPrime(check)) cout << "Yes\n";
    else                                  cout << "No\n";
  }

  return 0;
}
