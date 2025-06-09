#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

const int MOD = 1e9+7;

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

  int n; cin >> n;
  while(n--){

    int a, b; cin >> a >> b;
    cout << modPow(a, b, MOD) << "\n";
  }

  return 0;
}
