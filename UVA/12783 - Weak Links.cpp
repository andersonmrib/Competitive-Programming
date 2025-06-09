#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vector<pair<int, int>> bridges;

vi dfs_num, dfs_low, dfs_parent;
int dfsCounter;

enum {UNVISITED = -1};

void findBridges(int u){
  dfs_low[u] = dfs_num[u] = dfsCounter++;
  for (auto v : AL[u]){
    if (dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;

      findBridges(v);

      if (dfs_low[v] > dfs_num[u])
        bridges.push_back({min(u, v), max(u, v)});
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m), (n || m)){

    AL.assign(n, vi()); dfs_parent.assign(n, -1);
    dfs_low.assign(n, 0); dfs_num.assign(n, UNVISITED);
    bridges.clear();
    dfsCounter = 0;

    for(int i=0; i<m; i++){
      int u, v; cin >> u >> v;
      AL[u].emplace_back(v);
      AL[v].emplace_back(u);
    }

    for(int u=0; u<n; u++)
      if(dfs_num[u] == UNVISITED)
        findBridges(u);

    sort(bridges.begin(), bridges.end());

    cout << bridges.size();
    for(auto [u, v] : bridges)
      cout << " " << u << " " << v;
    cout << "\n";
  }

  return 0;
}
