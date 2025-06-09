#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy);

  while (t--) {
    getline(cin, dummy);

    int W, N; cin >> W >> N;
    vector<vector<int>> dp(W, vector<int>(N, 0));

    string line;
    getline(cin, line);
    int row, col;

    for (int i = 0; i < W; i++) {
      getline(cin, line);
      stringstream ss(line);
      ss >> row;
      row--;
      while (ss >> col) {
        col--;
        dp[row][col] = -1;
      }
    }

    if (dp[0][0] == -1) {
      cout << 0 << "\n";
      if (t) cout << "\n";
      continue;
    }

    for(int i=0; i<W && dp[i][0] != -1; i++) dp[i][0] = 1;
    for(int j=0; j<N && dp[0][j] != -1; j++) dp[0][j] = 1;

    for(int i=1; i<W; i++){
      for(int j=1; j<N; j++){
        if(dp[i][j] == -1) continue;
        if(dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
        if(dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
      }
    }

    cout << dp[W - 1][N - 1] << "\n";
    if (t) cout << "\n";
  }

  return 0;
}
