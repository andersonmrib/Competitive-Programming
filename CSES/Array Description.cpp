#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;


int main(){

  speedBoost;
  int n, m; cin >> n >> m;
  vi x(n);
  for(int i=0; i<n; i++)
    cin >> x[i];

  vector<vi> dp(n, vi(m+2, 0));
  if(x[0] == 0)
    for(int v=1; v<=m; v++) dp[0][v] = 1;
  else
    dp[0][x[0]] = 1;

  for(int i=1; i<n; i++){
    if(x[i] == 0){
      for(int v=1; v<=m; v++){
        for(int prev=v-1; prev <= v+1; prev++){
          if(prev >= 1 && prev <= m)
            dp[i][v] = (dp[i][v] + dp[i-1][prev]) % MOD;
        }
      }
    }
    else{
      int v = x[i];
      for(int prev=v-1; prev <= v+1; prev++){
        if(prev >= 1 && prev <= m)
          dp[i][v] = (dp[i][v] + dp[i-1][prev]) % MOD;
      }
    }
  }

  int ans = 0;
  for(int v=1; v<=m; v++)
    ans = (ans + dp[n-1][v]) % MOD;

  cout << ans << endl;

  return 0;
}
