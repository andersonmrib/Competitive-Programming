#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

const int INF = 1e9;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int get_weight(int u, int v){
  int diff = v - u;
  return diff * diff * diff;
}

int main() {

  speedBoost;
  int n, tc = 1;
  while (cin >> n){
    vi busyness(n);
    for (int i=0; i<n; i++)
      cin >> busyness[i];

    int r; cin >> r;
    vector<vii> AL(n);
    for (int i=0; i<r; i++){
      int u, v; cin >> u >> v;
      u--, v--;
      AL[u].push_back({v, get_weight(busyness[u], busyness[v])});
    }

    vi dist(n, INF);
    dist[0] = 0;

    for(int i=0; i<n-1; i++){
      bool modified = false;
      for(int u=0; u<n; u++){
        if(dist[u] == INF) continue;
        for(auto [v, w] : AL[u]){
          if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
            modified = true;
          }
        }
      }
      if (!modified) break;
    }

    for(int i=0; i<n; i++){
      for(int u=0; u<n; u++){
        if(dist[u] == INF) continue;
        for(auto &[v, w] : AL[u]){
          if(dist[u] + w < dist[v]){
            dist[v] = -INF;
          }
        }
      }
    }

    int q; cin >> q;
    cout << "Set #" << tc++ << endl;
    while (q--){
      int dest; cin >> dest;
      int idx = dest - 1;

      if (idx < 0 || idx >= n || dist[idx] < 3 || dist[idx] > INF / 2)
        cout << "?\n";
      else
        cout << dist[idx] << endl;
    }
  }

    return 0;
}
