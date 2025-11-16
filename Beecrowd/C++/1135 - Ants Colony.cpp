#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

int n, l;
vector<ll> dist;
vector<vector<ii>> AL;
vector<vi> up;

int timer;
vi tin, tout;

void dfs(int u, int p, int wei){

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

bool isAncestor(int u, int v){
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
  if(isAncestor(u, v))
    return u;
  if(isAncestor(v, u))
    return v;

  for(int i=l; i>=0; i--)
    if(!isAncestor(up[u][i], v))
      u = up[u][i];

  return up[u][0];
}

ll getDist(int u, int v){
  int anc = lca(u, v);
  return dist[u] + dist[v] - 2LL * dist[anc];
}

void preprocess(int root){
  tin.assign(n, 0);
  tout.assign(n, 0);
  dist.assign(n, 0);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vi(l+1));
  dfs(root, root, 0);
}

int main(){

  speedBoost; //
  while(cin >> n, n){

    AL.assign(n, vector<ii>());
    for(int i=1; i<n; i++){
      int b, w; cin >> b >> w;
      AL[i].emplace_back(b, w);
      AL[b].emplace_back(i, w);
    }

    preprocess(0);
    int q; cin >> q;
    while(q--){

      int u, v; cin >> u >> v;
      cout << getDist(u, v);
      if(q) cout << " ";
      else  cout << endl;
    }
  }

  return 0;
}
