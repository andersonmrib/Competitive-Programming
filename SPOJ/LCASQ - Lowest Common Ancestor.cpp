#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

struct LCA{

  vi euler, first, height, st;
  vector<bool> vis;
  int n;

  LCA(vector<vi> &AL, int root){
    n = AL.size();
    euler.reserve(2 * n);
    first.resize(n);
    height.resize(n);
    vis.assign(n, false);
    dfs(AL, root);
    int m = euler.size();
    st.resize(4 * m);
    build(1, 0, m-1);
  }

  void dfs(vector<vi> &AL, int u, int h = 0){
    vis[u] = true;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v : AL[u]){
      if(!vis[v]){
        dfs(AL, v, h+1);
        euler.push_back(u);
      }
    }
  }

  void build(int p, int L, int R){
    if(L == R) st[p] = euler[L];
    else{
      int m = (L+R)/2;
      build(p<<1, L, m);
      build(p<<1 | 1, m+1, R);
      int left = st[p<<1], right = st[p<<1|1];
      st[p] = (height[left] < height[right] ? left : right);
    }
  }

  int query(int p, int L, int R, int i, int j){
    if(L > j || R < i) return -1;
    if((L >= i) && (R <= j)) return st[p];
    int m = (L+R)/2;
    int left = query(p<<1, L, m, i, j);
    int right = query(p<<1|1, m+1, R, i, j);
    if(left == -1) return right;
    if(right == -1) return left;
    return (height[left] < height[right] ? left : right);
  }

  int lca(int u, int v){
    int left = first[u], right = first[v];
    if(left > right) swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }
};

int main(){

  speedBoost;
  int n; cin >> n;

  vector<vi> AL(n);
  for(int i=0; i<n; i++){
    int m; cin >> m;
    for(int j=0; j<m; j++){
      int node; cin >> node;
      AL[i].push_back(node);
    }
  }

  LCA useThis(AL, 0);

  int q; cin >> q;
  for(int i=0; i<q; i++){
    int u, v; cin >> u >> v;
    cout << useThis.lca(u, v) << endl;
  }

  return 0;
}
