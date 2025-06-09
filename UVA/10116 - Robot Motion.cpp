#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int R, C, E;
char grid[10][10];

void solve(int startCol){
  vector<vector<int>> visited(R, vector<int>(C, -1));
  int steps=0, r=0, c=startCol;

  while(true){
    if(r < 0 || r >= R || c < 0 || c >= C){
      cout << steps << " step(s) to exit\n";
      return;
    }

    if(visited[r][c] != -1){
      int loopStart = visited[r][c];
      cout << loopStart << " step(s) before a loop of " << steps - loopStart << " step(s)\n";
      return;
    }

    visited[r][c] = steps;
    steps++;

    if (grid[r][c] == 'N')      r--;
    else if (grid[r][c] == 'S') r++;
    else if (grid[r][c] == 'E') c++;
    else if (grid[r][c] == 'W') c--;
  }
}

int main(){

  speedBoost;
  while((cin >> R >> C >> E), (R || C || E)){
    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        cin >> grid[i][j];

    solve(E-1);
  }

  return 0;
}
