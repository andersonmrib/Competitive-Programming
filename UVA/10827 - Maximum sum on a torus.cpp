#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<vector<int>> dp(2*n, vector<int>(2*n));

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> dp[i][j];
        dp[i+n][j] = dp[i][j];
        dp[i][j+n] = dp[i][j];
        dp[i+n][j+n] = dp[i][j];
      }
    }

    for(int i=0; i<2*n; i++){
      for(int j=0; j<2*n; j++){
        if(i > 0) dp[i][j] += dp[i-1][j];
        if(j > 0) dp[i][j] += dp[i][j-1];
        if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
      }
    }

    int ans = INT_MIN;
    for(int i=0; i<2*n; i++){
      for(int j=0; j<2*n; j++){
        for(int k=i; k<2*n && k-i<n; k++){
          for(int l=j; l<2*n && l-j<n; l++){
            int subRect = dp[k][l];
            if(i > 0) subRect -= dp[i-1][l];
            if(j > 0) subRect -= dp[k][j-1];
            if(i > 0 && j > 0) subRect += dp[i-1][j-1];
            ans = max(ans, subRect);
          }
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
