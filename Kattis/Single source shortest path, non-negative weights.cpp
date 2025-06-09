#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;

const int INF = 1e9;

int main(){

  int n, m, q, s;
  while((cin >> n >> m >> q >> s), (n || m || q || s)){

    AL.assign(n, vii());
    for(int i=0; i<m; i++){
      int u, v, w; cin >> u >> v >> w;
      AL[u].emplace_back(v, w);
    }

    vi dist(n, INF); dist[s] = 0;

    set<ii> pq;
    for(int u=0; u<n; u++)
      pq.insert({dist[u], u});

    while(!pq.empty()){           // original Dijkstra with relaxing
      auto [d, u] = *pq.begin();  // and updating methods
      pq.erase(pq.begin());
      for(auto [v, w] : AL[u]){
        if(dist[u]+w >= dist[v]) continue;
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u]+w;
        pq.insert({dist[v], v});
      }
    }

    for(int i=0; i<q; i++){
      int query; cin >> query;
        if(dist[query] == INF) cout << "Impossible" << endl;
        else                   cout << dist[query] << endl;
    }
    cout << endl;
  }

  return 0;
}
