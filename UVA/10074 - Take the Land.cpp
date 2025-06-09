#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m), (n || m)){

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> dp[i][j];
        dp[i][j] = 1 - dp[i][j];
        if(j > 0) dp[i][j] += dp[i][j-1];
      }
    }

    int ans = 0;
    for(int l=0; l<m; l++){
      for(int r=l; r<m; r++){
        int width = r - l + 1, height = 0;
        for(int row=0; row<n; row++){
          int subRect = 0;

          if(l > 0) subRect += dp[row][r] - dp[row][l-1];
          else      subRect += dp[row][r];

          if(subRect == width) height++;
          else                 height = 0;

          ans = max(ans, subRect * height);
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
