#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

int main(){

  int N, M, C, K;
  while((cin >> N >> M >> C >> K), (N || M || K || C)){
    // cities, roads, cities in service route and stuck truck city
    vector<vii> AL(N, vii());
    for(int i=0; i<M; i++){
      int u, v, p; cin >> u >> v >> p;
      // we have two cities out of the route
      // or two consecutive cities in the route
      if((u >= C && v >= C) || (u < C && v < C && abs(u-v) == 1)){
        AL[u].emplace_back(v, p);
        AL[v].emplace_back(u, p);
      }
      // here just v makes part of the route, add u going to v
      else if(u >= C && v < C)
        AL[u].emplace_back(v, p);
      // here just u makes part of the route, add u receiving v
      else if(u < C && v >= C)
        AL[v].emplace_back(u, p);
    }

    // set origin vertex K to 0
    vi dist(M, INF); dist[K] = 0;

    set<ii> pq;
    for(int u=0; u<N; u++)
      pq.insert({dist[u], u});

    // simple Dijkstra
    while(!pq.empty()){
      auto [d, u] = *pq.begin();
      pq.erase(pq.begin());
      for(auto &[v, w] : AL[u]){
        if(dist[u]+w >= dist[v]) continue;
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u]+w;
        pq.insert({dist[v], v});
      }
    }
    cout << dist[C-1] << endl;
  }

    return 0;
}
