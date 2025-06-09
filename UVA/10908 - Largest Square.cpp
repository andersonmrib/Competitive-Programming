#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int M, N;
bool isValid(vector<string> &grid, int r, int c, int d, char ch){
  if(r - d < 0 || r + d >= M || c - d < 0 || c + d >= N)
    return false;

  for(int i=r-d; i<=r+d; i++)
    if(grid[i][c-d] != ch || grid[i][c+d] != ch)
      return false;

  for(int j=c-d; j<=c+d; j++)
    if(grid[r-d][j] != ch || grid[r+d][j] != ch)
      return false;

  return true;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int Q;
    cin >> M >> N >> Q;
    cout << M << " " << N << " " << Q << "\n";

    vector<string> grid(M);
    for(int i=0; i<M; i++)
      cin >> grid[i];

    while(Q--){
      int r, c;
      cin >> r >> c;
      char ch = grid[r][c];
      int d = 0;
      while(isValid(grid, r, c, d+1, ch))
        d++;
      cout << (2 * d + 1) << "\n";
    }
  }

  return 0;
}
