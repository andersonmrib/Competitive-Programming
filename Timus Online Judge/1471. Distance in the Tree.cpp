#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int n, l;
vector<vector<pair<int, int>>> AL;
vector<vi> up;

int timer;
vi tin, tout;
vector<long long> dist;

void dfs(int u, int p, long long wei){

  tin[u] = timer++;
  up[u][0] = p;

  if(u == p) dist[u] = 0;
  else       dist[u] = dist[p] + wei;

  for(int i=1; i<=l; i++)
    up[u][i] = up[up[u][i-1]][i-1];

  for(auto [v, w] : AL[u])
    if(v != p)
      dfs(v, u, w);
  tout[u] = timer++;
}

bool is_ancestor(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
  if(is_ancestor(u, v))
    return u;
  if(is_ancestor(v, u))
    return v;
  for(int i=l; i>=0; i--)
    if(!is_ancestor(up[u][i], v))
      u = up[u][i];
  return up[u][0];
}

void pre_process(int root){
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vi(l+1));
  dist.assign(n, 0);
  dfs(root, root, 0);
}

long long distNodes(int u, int v){
  int anc = lca(u, v);
  return dist[u] + dist[v] - 2LL * dist[anc];
}

int main(){

  speedBoost;
  cin >> n;

  AL.assign(n, vector<pair<int, int>>());
  for(int i=0; i<n-1; i++){
    int u, v, w; cin >> u >> v >> w;
    AL[u].emplace_back(v, w);
    AL[v].emplace_back(u, w);
  }

  pre_process(0);

  int m; cin >> m;
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v;
    cout << distNodes(u, v) << endl;
  }

  return 0;
}
