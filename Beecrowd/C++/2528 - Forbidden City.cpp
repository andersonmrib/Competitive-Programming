#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

typedef vector<int> vi;
vector<vi> AL;

int main(){

  int N, M, C, R, E;
  while(cin >> N >> M){

    AL.assign(N, vi());
    for(int i=0; i<M; i++){
      int a, b; cin >> a >> b;
      a--, b--;
      AL[a].emplace_back(b);
      AL[b].emplace_back(a);
    }
    cin >> C >> R >> E;
    C--, R--, E--;

    vi dist(N, INF); dist[C] = 0;
    queue<int> q; q.push(C);

    // BFS will naturally generate shortest path between
    // source S and destination D if the graph is unweighted
    while(!q.empty()){
      int u = q.front(); q.pop();
      if(u == E) continue;
      for(auto v : AL[u]){
        if(dist[v] == INF){
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
    }
    cout << dist[R] << endl;
  }

    return 0;
}
