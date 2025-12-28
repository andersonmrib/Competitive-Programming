#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define endl "\n"

using namespace std;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1) == 1) ans = ans * b % m;
  return ans;
}

int MOD = 10000007;

void solve(){

  int n, k;
  while(cin >> n >> k, n, k){

    int t1 = add_mod(fastPow(n, k, MOD), fastPow(n, n, MOD), MOD);
    int t2 = (fastPow(n-1, k, MOD) * 2) % MOD;
    int t3 = (fastPow(n-1, n-1, MOD) * 2) % MOD;
    int ans = add_mod(t1, add_mod(t2, t3, MOD), MOD);
    cout << ans << endl;
  }
}

int32_t main(){

  speedBoost;
    solve();

  return 0;
}
