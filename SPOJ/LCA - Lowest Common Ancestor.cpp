#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

struct LCA{

  vi euler, height, first, st;
  vector<bool> visited;
  int n;

  LCA(vector<vi> &AL, int root = 0){
    n = AL.size();
    euler.reserve(2 * n);
    height.resize(n);
    first.resize(n);
    visited.assign(n, false);
    dfs(AL, root);
    int m = euler.size();
    st.assign(4 * m, -1);
    build(1, 0, m - 1);
  }

  void dfs(vector<vi> &AL, int u, int h = 0){
    visited[u] = true;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v : AL[u]){
      if(!visited[v]){
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
      int left = st[p<<1], right = st[p<<1 | 1];
      st[p] = (height[left] < height[right] ? left : right);
    }
  }

  int query(int p, int L, int R, int i, int j){
    if(L > j || R < i) return -1;
    if((L >= i) && (R <= j)) return st[p];
    int m = (L+R)/2;
    int left = query(p<<1, L, m, i, j);
    int right = query(p<<1 | 1, m+1, R, i, j);
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
  int t; cin >> t;
  int NC = 1;
  while(t--){

    int n; cin >> n;
    vector<vi> AL(n);
    vector<bool> isChild(n, false);

    for(int i=0; i<n; i++){
      int m; cin >> m;
      for(int j=0; j<m; j++){
        int child; cin >> child;
        AL[i].push_back(child - 1);
        isChild[child - 1] = true;
      }
    }

    int root = -1;
    for(int i=0; i<n; i++){
      if(!isChild[i]){
        root = i;
        break;
      }
    }

    LCA useThis(AL);

    cout << "Case " << NC++ << ":\n";
    int q; cin >> q;
    while(q--){
      int u, v; cin >> u >> v;
      u--, v--;
      cout << useThis.lca(u, v) + 1 << endl;
    }
  }

  return 0;
}
