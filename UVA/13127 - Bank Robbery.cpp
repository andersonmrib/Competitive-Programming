#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, B, P;
vector<vii> AL;
vi dist;

void dijkstra(){

  set<ii> pq;
  for(int u=0; u<N; u++)
    pq.emplace(dist[u], u);

  while(!pq.empty()){
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());
    for(auto [v, w] : AL[u]){
      if(dist[u] + w >= dist[v]) continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] = dist[u] + w;
      pq.emplace(dist[v], v);
    }
  }
}

int main(){

  speedBoost;
  while(cin >> N >> M >> B >> P){

    AL.assign(N, vii());
    dist.assign(N, INF);

    for(int i=0; i<M; i++){
      int u, v, w; cin >> u >> v >> w;
      AL[u].emplace_back(v, w);
      AL[v].emplace_back(u, w);
    }

    vi banks;
    for(int i=0, x; i<B; i++)
      cin >> x, banks.push_back(x);
    for(int i=0, x; i<P; i++)
      cin >> x, dist[x] = 0;

    dijkstra();

    int maxDist = -1;
    for(auto b : banks)
      maxDist = max(maxDist, dist[b]);

    vi better;
    for(auto b : banks)
      if(dist[b] == maxDist)
        better.push_back(b);

    cout << better.size() << " ";
    if(maxDist == INF) cout << "*\n";
    else               cout << maxDist << "\n";

    sort(better.begin(), better.end());
    for(int i=0; i<better.size(); i++){
      if(i > 0) cout << " ";
      cout << better[i];
    }
    cout << "\n";
  }

  return 0;
}
