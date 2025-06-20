#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> tup;

vector<vii> AL;
vector<tup> edges;
vi dist_start, dist_end;

void dijkstra(int op, int p){
  vi &dist =  (op == 0) ? dist_start : dist_end;
  int start = (op == 0) ? 0 : p-1;
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
  int p, t; cin >> p >> t;

  edges.clear();
  AL.assign(p, vii());
  dist_start.assign(p, INF), dist_end.assign(p, INF);
  for(int i=0; i<t; i++){
    int u, v, w;
    cin >> u >> v >> w;
    AL[u].emplace_back(v, w);
    AL[v].emplace_back(u, w);
    edges.push_back({u, v, w});
  }

  dijkstra(0, p);
  dijkstra(1, p);

  int ans = 0;
  for(auto [u, v, w] : edges){
    if(dist_start[u] + w + dist_end[v] == dist_start[p-1] ||
      (dist_start[v] + w + dist_end[u] == dist_start[p-1]))
        ans += 2 * w;
  }

  cout << ans << "\n";

  return 0;
}
