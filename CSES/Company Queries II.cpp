#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

int n, l;
vector<vi> AL, up;

int timer;
vi tin, tout;

void dfs(int u, int p){

  tin[u] = timer++;
  up[u][0] = p;

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

void preprocess(int root){
  tin.assign(n, 0);
  tout.assign(n,  0);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vi(l+1));
  dfs(root, 0);
}

int main(){

  speedBoost;
  int q;
  cin >> n >> q;

  AL.assign(n, vi());
  for(int i=1; i<n; i++){
    int boss; cin >> boss;
    boss--;
    AL[boss].push_back(i);
    AL[i].push_back(boss);
  }

  preprocess(0);
  while(q--){

    int a, b; cin >> a >> b;
    a--, b--;
    cout << lca(a, b) + 1 << endl;
  }

  return 0;
}
