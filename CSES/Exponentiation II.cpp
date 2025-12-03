#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

const int MOD = 1e9+7;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = (ans*ans) % m;
  if(p&1) ans = (ans*b) % m;
  return ans;
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  while(n--){

    int a, b, c; cin >> a >> b >> c;
    int exp = fastPow(b, c, MOD-1);
    int ans = fastPow(a, exp, MOD);
    cout << ans << endl;
  }

  return 0;
}
