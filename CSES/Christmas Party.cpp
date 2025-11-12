#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

const int MAX_N = 1e6+1;
const int MOD = 1e9+7;

int32_t main(){

  int n; cin >> n;
  int dp[n+1];
  dp[0] = 1, dp[1] = 0;
  for(int i=1; i<n+1; i++)
    dp[i] = (i - 1) * (dp[i-1] + dp[i-2]) % MOD;

  cout << dp[n] << endl;

  return 0;
}
