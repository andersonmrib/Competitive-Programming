#include <bits/stdc++.h> // Bottom Up version
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;

    // 1 for vertical moves, ans 0 for horizontal ones
    vector<vector<vector<bool>>> blocked(n, vector<vector<bool>>(n, vector<bool>(2)));
    int w; cin >> w;
    for(int i=0; i<w; i++){
      int px, py; char c;
      cin >> px >> py >> c;
      px--, py--;

      if(c == 'S') blocked[px][py-1][1] = true;
      if(c == 'N') blocked[px][py][1] = true;
      if(c == 'E') blocked[px][py][0] = true;
      if(c == 'W') blocked[px-1][py][0] = true;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[sx][sy] = 1;

    for(int i=sx; i<=ex; i++){
      for(int j=sy; j<=ey; j++){
        if(i == sx && j == sy) continue;
        if(i > 0 && !blocked[i-1][j][0]) dp[i][j] += dp[i-1][j]; // go east
        if(j > 0 && !blocked[i][j-1][1]) dp[i][j] += dp[i][j-1]; // go north
      }
    }

    cout << dp[ex][ey] << "\n";
  }

  return 0;
}

/*
// Lambda version (Top-Down)
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;

    // 1 for vertical moves, ans 0 for horizontal ones
    vector<vector<vector<bool>>> blocked(n, vector<vector<bool>>(n, vector<bool>(2)));
    int w; cin >> w;
    for(int i=0; i<w; i++){
      int px, py; char c;
      cin >> px >> py >> c;
      px--, py--;

      if(c == 'S') blocked[px][py-1][1] = true;
      if(c == 'N') blocked[px][py][1] = true;
      if(c == 'E') blocked[px][py][0] = true;
      if(c == 'W') blocked[px-1][py][0] = true;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> solve = [&] (int i, int j) -> int{
      if(i == ex && j == ey) return 1;
      if(i >= n || j >= n) return 0;

      int &ans = dp[i][j];
      if(ans != -1) return ans;

      ans = 0;
      if(!blocked[i][j][1]) ans += solve(i, j+1);
      if(!blocked[i][j][0]) ans += solve(i+1, j);

      return ans;
    };

    cout << solve(sx, sy) << "\n";
  }

  return 0;
}
*/
