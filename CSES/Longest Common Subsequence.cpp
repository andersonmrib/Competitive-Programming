#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  vi a(n), b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];
  vector<vi> dp(n+1, vi(m+1, 0));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  cout << dp[n][m] << endl;
  vi lcs;
  int i = n, j = m;
  while(i > 0 && j > 0){
    if(a[i-1] == b[j-1]){
      lcs.push_back(a[i-1]);
      i--, j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
      i--;
    else
      j--;
  }

  reverse(lcs.begin(), lcs.end());
  for(int k=0; k<lcs.size(); k++)
    cout << lcs[k] << (k == lcs.size() - 1 ? "" : " ");
  cout << endl;

  return 0;
}
