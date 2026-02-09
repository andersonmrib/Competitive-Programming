#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  string s1, s2; cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  vector<vi> dp(n+1, vi(m+1));
  for(int i=0; i<=n; i++){
    for(int j=0; j<=m; j++){
      if(i == 0)
        dp[i][j] = j;
      else if(j == 0)
        dp[i][j] = i;
      else if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
