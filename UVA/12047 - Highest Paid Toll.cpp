#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> tup;

vector<vii> AL, AL_rev;
vi dist, dist_rev;
vector<tup> edges;

void dijkstra(int s, int n, int pass, vi &distDij){

  set<ii> pq;
  vector<vii> &g = (pass == 0) ? AL : AL_rev;
  distDij[s] = 0;
  for(int u=0; u<n; u++)
    pq.emplace(distDij[u], u);
  while(!pq.empty()){
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());
    for(auto [v, w] : g[u]){
      if(distDij[u] + w >= distDij[v]) continue;
      pq.erase(pq.find({distDij[v], v}));
      distDij[v] = distDij[u] + w;
      pq.emplace(distDij[v], v);
    }
  }
}

int main(){

  speedBoost;
  int T; cin >> T;
  int n, m, s, t, p;
  while(T--){

    cin >> n >> m >> s >> t >> p;
    s--, t--;

    AL.assign(n, vii()), AL_rev.assign(n, vii());
    dist.assign(n, INF), dist_rev.assign(n, INF);
    edges.clear();

    for(int i=0; i<m; i++){
      int u, v, w; cin >> u >> v >> w;
      u--, v--;
      AL[u].emplace_back(v, w);
      AL_rev[v].emplace_back(u, w);
      edges.emplace_back(u, v, w);
    }

    dijkstra(s, n, 0, dist);
    dijkstra(t, n, 1, dist_rev);

    int ans = -1;
    for(auto [u, v, w] : edges){
      if(dist[u] != INF && dist_rev[v] != INF){
        int path_cost = dist[u] + w + dist_rev[v];
        if(path_cost <= p)
          ans = max(ans, w);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
