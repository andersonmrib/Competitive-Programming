#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int grid[102][102];
bool unsafe[102][102], visited[102][102];

typedef pair<int, int> ii;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    memset(grid, 0, sizeof grid);
    memset(unsafe, 0, sizeof unsafe);
    memset(visited, 0, sizeof visited);

    int r, c, m, n, w;
    cin >> r >> c >> m >> n >> w;

    int dr[] = {m, m, -m, -m, n, n, -n, -n};
    int dc[] = {n, -n, n, -n, m, -m, m, -m};

    for(int i=0; i<w; i++){
      int a, b; cin >> a >> b;
      unsafe[a][b] = true;
    }

    visited[0][0] = true;
    queue<ii> q; q.push({0, 0});
    while(!q.empty()){

      auto [x, y] = q.front(); q.pop();

      int newX, newY;
      set<ii> diff;
      for(int d=0; d<8; d++){
        newX = x + dr[d];
        newY = y + dc[d];
        diff.insert({newX, newY});
      }

      for(auto it : diff){
        newX = it.first, newY = it.second;
        if((newX >= 0 && newX < r && newY >= 0 && newY < c) && !unsafe[newX][newY]){
            grid[newX][newY]++;
          if(!visited[newX][newY]){
            visited[newX][newY] = true;
            q.push({newX, newY});
          }
        }
      }
    }

    int even = 0, odd = 0;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(grid[i][j] || (!i && !j)){
          if(grid[i][j] % 2) odd++;
          else               even++;
        }
      }
    }

    cout << "Case " << ++numCases << ": " << even << " " << odd << "\n";
  }

  return 0;
}
