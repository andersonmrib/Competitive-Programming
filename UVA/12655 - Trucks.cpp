#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef tuple<int, int, int> tup;

class UnionFind{

private:
  vi p, rank;

public:

  int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y])
      rank[y]++;
  }

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
  }

};

class LCA{

private:
  vi euler, height, first, st, parent, weightToParent;
  vector<bool> visited;
  vector<vector<ii>> AL;
  int n;

public:

  void dfs(int u, int h = 0, int p = -1, int w = INT_MAX){
    visited[u] = true;
    height[u] = h;
    parent[u] = p;
    weightToParent[u] = w;
    first[u] = euler.size();
    euler.push_back(u);
    for(auto [v, ww] : AL[u]){
      if(!visited[v]) dfs(v, h+1, u, ww);
      euler.push_back(u);
    }
  }

  LCA(vector<vector<ii>> AL){
    this->AL = AL;
    n = AL.size();
    euler.reserve(2 * n);
    height.assign(n, 0);
    parent.assign(n, -1);
    weightToParent.assign(n, INT_MAX);
    first.assign(n, 0);
    visited.assign(n, false);
    dfs(0);
    int m = euler.size();
    st.resize(m * 4);
    build(1, 0, m-1);
  }

  void build(int p, int b, int e){
    if(b == e)
      st[p] = euler[b];
    else{
      int mid = (b + e)/2;
      build(p<<1, b, mid);
      build(p<<1 | 1, mid+1, e);
      int l = st[p<<1], r = st[p<<1|1];
      st[p] = (height[l] < height[r]) ? l : r;
    }
  }

  int query(int p, int b, int e, int L, int R){
    if(b > R || e < L)
      return -1;
    if(b >= L && e <= R)
      return st[p];
    int mid = (b + e)/2;
    int left = query(p<<1, b, mid, L, R);
    int right = query(p<<1|1, mid+1, e, L, R);
    if(left == -1)  return right;
    if(right == -1) return left;
    return height[left] < height[right] ? left : right;
  }

  int lca(int u, int v){
    int left = first[u], right = first[v];
    if(left > right) swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }

  int minEdgePath(int u, int anc){
    int ans = INT_MAX;
    while(u != anc){
      ans = min(ans, weightToParent[u]);
      u = parent[u];
    }
    return ans;
  }

};

int main(){

  speedBoost;
  int n, m, s;
  while(cin >> n >> m >> s){

    vector<tup> edges(m);
    for(int i=0; i<m; i++){
      int a, b, w; cin >> a >> b >> w;
      a--, b--;
      edges[i] = {w, a, b};
    }

    sort(edges.rbegin(), edges.rend());
    UnionFind UF(n);
    vector<vector<ii>> AL(n);

    for(auto [w, a, b] : edges){
      if(!UF.isSameSet(a, b)){
        UF.unionSet(a, b);
        AL[a].emplace_back(b, w);
        AL[b].emplace_back(a, w);
      }
    }

    LCA lca(AL);

    while(s--){
      int l, h; cin >> l >> h; l--, h--;
      int anc = lca.lca(l, h);
      int ans = min(lca.minEdgePath(l, anc), lca.minEdgePath(h, anc));
      cout << ans << endl;
    }
  }

  return 0;
}
