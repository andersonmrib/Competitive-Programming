#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi dist;

int dijkstra(int s, int t, int C){

  set<ii> pq;
  dist[0] = 0;
  for(int u=0; u<2*C; u++)
    pq.emplace(dist[u], u);

  while(!pq.empty()){
    auto [d, u] = *pq.begin();
    if(u == t) return d;
    pq.erase(pq.begin());
    for(auto [v, w] : AL[u]){
      if(dist[u] + w >= dist[v]) continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] = dist[u] + w;
      pq.emplace(dist[v], v);
    }
  }
  return -1;
}

int main(){

  speedBoost;
  int C, V;
  while(cin >> C >> V){

    AL.assign(C*2, vii());
    dist.assign(2*C, INF);
    for(int i=0; i<V; i++){
      int u, v, w; cin >> u >> v >> w;
      u--, v--;
      AL[u].emplace_back(v+C, w);
      AL[v].emplace_back(u+C, w);
      AL[u+C].emplace_back(v, w);
      AL[v+C].emplace_back(u, w);
    }

    int ans = dijkstra(0, C-1, C);
    if(ans == -1 || ans == INF) cout << "-1\n";
    else           cout << dist[C-1] << "\n";
  }

  return 0;
}
