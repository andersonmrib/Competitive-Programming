#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;
  int w, h;
  while((cin >> w >> h), (w || h)){

    vector<vector<int>> dp(w+1, vector<int>(h+1, 0));

    int n; cin >> n;
    for(int i=0; i<n; i++){
      int x, y; cin >> x>> y;
      dp[x][y] = -1;
    }

    if(dp[0][0] == -1){
      cout << "There is no path.\n";
      continue;
    }

    dp[0][0] = 1;
    for(int i=0; i<=w; i++){
      for(int j=0; j<=h; j++){
        if(dp[i][j] == -1) continue;
        if(i > 0 && dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
        if(j > 0 && dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
      }
    }

    int ans = dp[w][h];
    if (ans == 0)
      cout << "There is no path.\n";
    else if (ans == 1)
      cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
    else
      cout << "There are " << ans << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
  }

  return 0;
}
