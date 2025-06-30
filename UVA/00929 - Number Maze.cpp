#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 1e9;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        cin >> maze[i][j];

      vector<vector<int>> dist(n, vector<int>(m, INF));
      priority_queue<iii, vector<iii>, greater<iii>> pq;

      dist[0][0] = maze[0][0];
      pq.emplace(dist[0][0], 0, 0); // (cost, x, y)
      while(!pq.empty()){
        auto [cost, x, y] = pq.top(); pq.pop();
        if(cost > dist[x][y]) continue;

        for(int d=0; d<4; d++){
          int nx = x + dr[d], ny = y + dc[d];
          if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            int new_cost = cost + maze[nx][ny];
            if(new_cost < dist[nx][ny]){
              dist[nx][ny] = new_cost;
              pq.emplace(new_cost, nx, ny);
            }
          }
        }
      }

      cout << dist[n-1][m-1] << "\n";
  }

  return 0;
}
