#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int N, S;
int foundSol, startCol;
int dp[45][25][505], grid[45][25];
bool memo[45][25][505];
string res;

int solve(int i, int j, int s, string path){
  if(s < 0) return 0; // prune this

  if(s == 0 && i == 2*N-1){ // found solution
    if(foundSol == -1){
      foundSol = startCol;
      res = path;
    }
    return 1;
  }

  if(i >= 2*N-1) return 0; // prune again
  if(memo[i][j][s]) return dp[i][j][s];
  memo[i][j][s] = true;

  int &ans = dp[i][j][s];

  if(i < N-1){
    if(grid[i+1][j-1] != -1) ans += solve(i+1, j-1, s-grid[i][j], path+'L');
    if(grid[i+1][j]   != -1) ans += solve(i+1, j, s-grid[i][j], path+'R');
  }
  else{
    if(i+1 == 2*N-1) ans += solve(i+1, j, s-grid[i][j], path);
    else{
      if(grid[i+1][j]   != -1) ans += solve(i+1, j, s-grid[i][j], path+'L');
      if(grid[i+1][j+1] != -1) ans += solve(i+1, j+1, s-grid[i][j], path+'R');
    }
  }
  return ans;
}

int32_t main(){

  speedBoost;
  while((cin >> N >> S), (N || S)){

    memset(grid, -1, sizeof grid);
    memset(dp, 0, sizeof dp);
    memset(memo, false, sizeof memo);

    for(int i=0; i<N; i++)
      for(int j=0; j<N-i; j++)
        cin >> grid[i][j];

    for(int i=N; i<2*N-1; i++)
      for(int j=0; j<=i-N+1; j++)
        cin >> grid[i][j];

    int numDistinctPaths = 0;
    foundSol = -1, startCol = 0;
    for(int j=0; j<N; j++, startCol++)
      numDistinctPaths += solve(0, j, S, "");

    cout << numDistinctPaths << "\n";
    if(!numDistinctPaths) cout << "\n";
    else cout << foundSol << " " << res << "\n";
  }

  return 0;
}
