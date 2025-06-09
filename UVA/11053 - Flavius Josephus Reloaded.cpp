#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

ll a, b, N;

ll f(ll x) { return (a * (x * x % N) + b) % N; }

ll floydCycleFinding(ll x0){

  ll t = f(x0), h = f(f(x0));
  while(t != h) { t = f(t), h = f(f(h)); }

  h = x0;
  while(t != h) { t = f(t), h = f(h); }

  ll lambda = 1; h = f(t);
  while(t != h) { h = f(h), lambda++; };

  return lambda;
}

int main(){

  speedBoost;
  while(cin >> N >> a >> b){

    if(N == 0) break;
    ll lambda = floydCycleFinding(0);
    cout << N - lambda << "\n";
  }

  return 0;
}


