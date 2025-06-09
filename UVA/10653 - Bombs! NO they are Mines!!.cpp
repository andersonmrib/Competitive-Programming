#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define MAX 1001
typedef pair<int, int> ii;

int R, C;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int grid[MAX][MAX];
bool visited[MAX][MAX];

bool reachable(int r, int c){
  if(r >= 0 && r < R && c >= 0 && c < C) return true;
  return false;
}

int bfs(int row, int col, int finalRow, int finalCol){

  memset(visited, false, sizeof visited);
  queue<ii> q; q.push({row, col});

  grid[row][col] = 0;
  visited[row][col] = true;

  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    if(r == finalRow && c == finalCol)
      return grid[r][c];

    for(int d=0; d<4; d++){
      int newR =  r + dr[d];
      int newC = c + dc[d];

      if(reachable(newR, newC) && grid[newR][newC] != -1 && !visited[newR][newC]){
        visited[newR][newC] = true;
        grid[newR][newC] = grid[r][c] + 1;
        q.push({newR, newC});
      }
    }
  }
  return -1;
}


int main(){

  speedBoost;
  while((cin >> R >> C), (R || C)){

    memset(grid, 0, sizeof grid);
    int numBombs; cin >> numBombs;

    for(int i=0; i<numBombs; i++){
      int rowId, qt; cin >> rowId >> qt;
      for(int j=0; j<qt; j++){
        int colId; cin >> colId;
        grid[rowId][colId] = -1;
      }
    }
    int startX, startY, finalX, finalY;
    cin >> startX >> startY >> finalX >> finalY;

    int ans = bfs(startX, startY, finalX, finalY);
    cout << ans << "\n";
  }

  return 0;
}
