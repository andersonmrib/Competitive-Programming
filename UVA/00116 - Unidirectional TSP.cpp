#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    vector<vi> grid(n, vi(m)), dp(n, vi(m)), path(n, vi(m, -1));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> grid[i][j];
      }
      dp[i][m-1] = grid[i][m-1];
    }

    for(int j=m-2; j>=0; j--){
      for(int i=0; i<n; i++){
        int dir[] = {(i+1)%n, i, (i-1+n)%n};
        sort(dir, dir + 3);
        int bestRow = -1, bestVal = INT_MAX;
        for(auto d : dir){
          int prev = dp[d][j+1];
          if(prev < bestVal){
            bestVal = prev;
            bestRow = d;
          }
        }
        dp[i][j] = bestVal + grid[i][j];
        path[i][j] = bestRow;
      }
    }

    int startRow = -1, bestCost = INT_MAX;
    for(int i=0; i<n; i++){
      if(dp[i][0] < bestCost){
        startRow = i;
        bestCost = dp[i][0]; // Result 2 here!
      }
    }

    vi reconstruct(m);
    int r = startRow;
    for(int j=0; j<m; j++){
      reconstruct[j] = r+1;
      if(j < m-1)
        r = path[r][j];
    }

    for(int j=0; j<m; j++){
      if(j) cout << " ";
      cout << reconstruct[j];
    }
    cout << "\n";

    cout << bestCost << "\n";
  }

  return 0;
}
