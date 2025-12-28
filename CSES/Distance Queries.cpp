#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int n, l;
vector<vi> AL, up;
vi dist;

int timer;
vi tin, tout;

void dfs(int u, int p){

  tin[u] = timer++;
  up[u][0] = p;

  if(u == p) dist[u] = 0;
  else       dist[u] = dist[p] + 1;

  for(int i=1; i<=l; i++)
      up[u][i] = up[up[u][i-1]][i-1];

  for(auto v : AL[u])
    if(v != p)
      dfs(v, u);

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

int getDist(int u, int v){
  int anc = lca(u, v);
  return dist[u] + dist[v] - 2LL * dist[anc];
}

void pre_proces(int root){
  tin.assign(n, 0);
  tout.assign(n, 0);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vi(l+1, -1));
  dist.assign(n, 0);
  dfs(root, root);
}

int main(){

  speedBoost;
  int q;
  cin >> n >> q;

  AL.assign(n, vi());
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    AL[b].push_back(a);
  }

  pre_proces(0);
  while(q--){

    int a, b; cin >> a >> b;
    a--, b--;
    cout << getDist(a, b) << endl;
  }

  return 0;
}
