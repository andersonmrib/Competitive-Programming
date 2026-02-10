#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int dp[1007][1007];

int32_t main(){

  speedBoost;
  string a, b;
  while(getline(cin, a) && getline(cin, b)){

    memset(dp, 0, sizeof dp);
    int n = a.size(), m = b.size();
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        int op1 = dp[i-1][j-1] + (a[i-1] == b[j-1] ? 1 : -1e9);
        int op2 = dp[i-1][j];
        int op3 = dp[i][j-1];
        dp[i][j] = max({op1, op2, op3});
      }
    }

    cout << dp[n][m] << endl;
  }

  return 0;
}
