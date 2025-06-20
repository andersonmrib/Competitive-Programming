#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> tup;
vector<vii> AL, AL_rev;
vector<tup> edges;

void dijkstra(int start, int p, vi &dist){
  set<ii> pq;
  dist[start] = 0;
  for(int u=0; u<p; u++)
    pq.insert({dist[u], u});

  while(!pq.empty()){
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());
    for(auto [v, w] : AL[u]){
      if(dist[u] + w >= dist[v]) continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] = dist[u] + w;
      pq.insert({dist[v], v});
    }
  }
}

int main(){

  speedBoost;
  int p, t;
  while(cin >> p >> t){

    AL.assign(p, vii());
    AL_rev.assign(p, vii());
    edges.clear();

    for(int i=0; i<t; i++){
      int u, v, w;
      cin >> u >> v >> w;
      AL[u].emplace_back(v, w);
      AL[v].emplace_back(u, w);
      edges.push_back({u, v, w});
    }

    vi dist_start(p, INF), dist_end(p, INF);
    dijkstra(0, p, dist_start);
    dijkstra(p-1, p, dist_end);

    int ans = 0;
    for(auto [u, v, w] : edges){
      if(dist_start[u] + w + dist_end[v] == dist_start[p-1] ||
         dist_start[v] + w + dist_end[u] == dist_start[p-1])
           ans += 2 * w;
    }

    cout << ans << "\n";
  }

  return 0;
}
