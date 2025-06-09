#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int N = 8;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};


bool isInside(int x, int y){
  return x >= 0 && x < N && y >= 0 && y < N;
}

int solve(string start, string end){
  if(start == end) return 0;

  int sx = start[0] - 'a';
  int sy = start[1] - '1';
  int ex = end[0] - 'a';
  int ey = end[1] - '1';

  int dist[N][N];
  memset(dist, -1, sizeof dist);
  queue<pair<int, int>> q;
  q.push({sx, sy});
  dist[sx][sy] = 0;

  while(!q.empty()){

    auto [x, y] = q.front();
    q.pop();

    for(int i=0; i<8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isInside(nx, ny) && dist[nx][ny] == -1){
        dist[nx][ny] = dist[x][y] + 1;
        if(nx == ex && ny == ey) return dist[nx][ny];
        q.push({nx, ny});
      }
    }
  }
  return -1;
}

int main(){

  speedBoost;
  string a, b;
  while(cin >> a >> b){

    int ans = solve(a, b);
     cout << "To get from " << a << " to " << b <<
    " takes " << ans << " knight moves." << "\n";
  }

  return 0;
}
