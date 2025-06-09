#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

ll mod(ll a, ll m) { return ((a % m) + m) % m; }

ll modPow(ll b, ll p, ll m){
  if(p == 0) return 1;
  ll ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if(p&1) ans = mod(ans*b, m);
  return ans;
}

int main(){

  speedBoost;
  ll b, p, m;
  while(cin >> b >> p >> m){
    cout << modPow(b, p, m) << "\n";
  }

  return 0;
}
