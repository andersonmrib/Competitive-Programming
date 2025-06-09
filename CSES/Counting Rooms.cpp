#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int R, C;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

char grid[1001][1001];

void floofill(int r, int c){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return;
  if(grid[r][c] != '.') return;

  stack<pair<int, int>> st;
  st.push({r, c});
  grid[r][c] = '#';

  while(!st.empty()){
    int x = st.top().first;
    int y = st.top().second;
    st.pop();

    for(int d=0; d<4; d++){
      int nr = x + dr[d], nc = y + dc[d];
      if((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C) && grid[nr][nc] == '.'){
        st.push({nr, nc});
        grid[nr][nc] = '#';
      }
    }
  }
}

int main(){

  speedBoost;
  cin >> R >> C;

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      cin >> grid[i][j];

  int ans = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(grid[i][j] == '.'){
        ans++, floofill(i, j);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}