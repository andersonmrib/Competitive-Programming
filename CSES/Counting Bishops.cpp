#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;

int squares(int i){
  if(i&1) return i / 4 * 2 + 1;
  else    return (i - 1) / 4 * 2 + 2;
}

int bishop_placement(int n, int k){

  if(k > 2 * n - 1)
    return 0;

  vector<vi> dp(n * 2, vi(k + 1));
  for(int i=0; i<n*2; i++)
    dp[i][0] = 1;
  dp[1][1] = 1;
  for(int i=2; i<n*2; i++)
    for(int j=1; j<=k; j++)
      dp[i][j] = (dp[i-2][j] + dp[i-2][j-1] * (squares(i) - j + 1)) % MOD;

  int ans = 0;
  for(int i=0; i<=k; i++)
    ans = (ans + dp[2*n-1][i] * dp[2*n-2][k-i]) % MOD;
  return ans;
}

int32_t main(){

  speedBoost;
  int n, k; cin >> n >> k;
  cout << bishop_placement(n, k) % MOD << endl;

  return 0;
}

