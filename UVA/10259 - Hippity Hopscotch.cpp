#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<int>> grid, memo;
int n, k;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool possible(int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < n);
}

void dp(int x, int y){
  if(memo[x][y] != -1) return;
  memo[x][y] = grid[x][y];
  for(int d=0; d<4; d++){
    for(int z=1; z<=k; z++){
      int nx = x + dr[d] * z;
      int ny = y + dc[d] * z;
      if(possible(nx, ny) && grid[nx][ny] > grid[x][y]){
        dp(nx, ny);
        memo[x][y] = max(memo[x][y], grid[x][y] + memo[nx][ny]);
      }
    }
  }
}

// Another way
int dp2(int x, int y){
  if(memo[x][y] != -1) return memo[x][y];
  int best = 0;
  for(int d=0; d<4; d++){
    for(int z=1; z<=k; z++){
      int nx = x + dr[d] * z;
      int ny = y + dc[d] * z;
      if(possible(nx, ny) && grid[nx][ny] > grid[x][y])
        best = max(best, dp2(nx, ny));
    }
  }
  return memo[x][y] = grid[x][y] + best;
}

int main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy);
  getline(cin, dummy);
  while(t--){

     cin >> n >> k;
     grid.assign(n, vector<int>(n));
     memo.assign(n, vector<int>(n, -1));
     for(int i=0; i<n; i++)
       for(int j=0; j<n; j++)
         cin >> grid[i][j];

     dp(0, 0);
     cout << memo[0][0] << "\n";

     if(t){
      cout << "\n";
      getline(cin, dummy);
      getline(cin, dummy);
     }
  }

  return 0;
}

