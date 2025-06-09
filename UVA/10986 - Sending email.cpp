#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> AL;

const int INF = 1e9;

int main(){

  int numCases = 0;
  int N; cin >> N;
  while(N--){

    int n, m, s, t; cin >> n >> m >> s >> t;

    AL.assign(n, vii());
    vi dist(n, INF); dist[s] = 0;

    for(int i=0; i<m; i++){
      int a, b, w; cin >> a >> b >> w;
      AL[a].emplace_back(b, w);
      AL[b].emplace_back(a, w);
    }

    set<ii> pq;
    for(int u=0; u<n; u++)
    pq.insert({dist[u], u});

    while(!pq.empty()){
      auto[d, u] = *pq.begin();
      pq.erase(pq.begin());
      for(auto &[v, w] : AL[u]){
        if(dist[u]+w >= dist[v]) continue;
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u]+w;
        pq.insert({dist[v], v});
      }
    }
    cout << "Case #" << ++numCases << ": ";
    if(dist[t] == INF) cout << "unreachable" << endl;
    else               cout << dist[t] << endl;
  }

  return 0;
}
