#include<bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000007
#define int long long
using namespace std;

int mod(int a, int m) { return ((a%m)+m)%m; }

int modPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if(p&1) ans = mod(ans*b, m);
  return ans;
}

int32_t main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n; cin >> n;
    cout << "Case #" << ++NC << ": " << (n * modPow(2, n-1, MOD))%MOD << "\n";
  }

  return 0;
}
