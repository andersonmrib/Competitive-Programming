#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define MAX 1000
char grid[MAX][MAX];
int R, C;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return;
  if(grid[r][c] != '.') return;

  stack<pair<int, int>> st4ck;
  st4ck.push({r, c});
  grid[r][c] = 'o';

  while(!st4ck.empty()){
    int x = st4ck.top().first;
    int y = st4ck.top().second;
    st4ck.pop();

    for(int d=0; d<4; d++){
      int nr = x + dr[d];
      int nc = y + dc[d];
      if((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C) && grid[nr][nc] == '.'){
        st4ck.push({nr, nc});
        grid[nr][nc] = 'o';
      }
    }
  }
}

int main(){

  cin >> R >> C;

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      cin >> grid[i][j];

  int ans = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(grid[i][j] == '.'){
        ans++;
        floodfill(i, j);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
