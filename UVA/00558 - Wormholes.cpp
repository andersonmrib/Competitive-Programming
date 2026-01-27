#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

const int INF = 1e9;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AL;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    AL.assign(n, vii());
    for(int i=0; i<m; i++){
      int u, v, w; cin >> u >> v >> w;
      AL[u].emplace_back(v, w);
    }

    int s = 0;
    vi dist(n, INF);
    dist[s] = 0;

    for(int i=0; i<n-1; i++){
      bool modified = false;
      for(int u=0; u<n; u++){
        if(dist[u] != INF){
          for(auto [v, w] : AL[u]){
            if(dist[u] + w < dist[v]){
              dist[v] = dist[u] + w;
              modified = true;
            }
          }
        }
      }
      if(!modified) break;
    }

    bool hasNegativeCycle = false;
    for(int u=0; u<n; u++){
      if(dist[u] != INF){
        for(auto [v, w] : AL[u]){
          if(dist[v] > dist[u] + w){
            hasNegativeCycle = true;
            break;
          }
        }
      }
      if(hasNegativeCycle) break;
    }

    if(hasNegativeCycle)
      cout << "possible\n";
    else
      cout << "not possible\n";
  }

  return 0;
}
