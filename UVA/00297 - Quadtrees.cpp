#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int grid[32][32];
char c;

void draw(int r, int c, int side){
  for(int i=r; i<r+side; i++)
    for(int j=c; j<c+side; j++)
      grid[i][j] = 1;
}

void dfs(int row, int col, int side){
  cin >> c;
  if(c == 'p'){
    int newSide = side / 2;
    dfs(row, col + newSide, newSide);
    dfs(row, col, newSide);
    dfs(row + newSide, col, newSide);
    dfs(row + newSide, col + newSide, newSide);
  }
  else if(c == 'f') draw(row, col, side);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    memset(grid, 0, sizeof grid);
    int ans = 0;
    dfs(0, 0, 32);
    dfs(0, 0, 32);
    for(int i=0; i<32; i++)
      for(int j=0; j<32; j++)
        if(grid[i][j]) ans++;

    cout << "There are ";
    cout << ans << " ";
    cout << "black pixels.\n";
  }

  return 0;
}
