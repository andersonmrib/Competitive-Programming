#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  int fib[41]; fib[0] = 0, fib[1] = 1, fib[2] = 1;
  for(int i=3; i<=41; i++) fib[i] = fib[i-1] + fib[i-2];

  int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

  int t; cin >> t;
  while(t--){

    int n, a, b; cin >> n >> a >> b;

    map<int, int> factors;

    for(int i=0; i<15; i++)
      while(a%primes[i] == 0){
        factors[primes[i]] += fib[n-1];
        a /= primes[i];
      }
    if(a != 1) factors[a] += fib[n-1];

    for(int i=0; i<15; i++)
      while(b%primes[i] == 0){
        factors[primes[i]] += fib[n];
        b /= primes[i];
      }
    if(b != 1) factors[b] += fib[n];

    for(auto [f, s] : factors)
      cout << f << " " << s << "\n";
    cout << "\n";
  }


  return 0;
}
