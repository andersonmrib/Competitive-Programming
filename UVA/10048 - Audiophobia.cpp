#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> edge;

vector<vii> AL;
vi dfs_num;

enum {UNVISITED = -1, VISITED = -2};

class UnionFind{

private:
  vi p, rank;

public:

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
  }

  int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
  }
};

void dfs(int u, int target, int maxEdge, vi &dfs_num, int &ans){
  if(u == target){
    ans = maxEdge;
    return;
  }
  dfs_num[u] = VISITED;
  for(auto [v, w] : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v, target, max(maxEdge, w), dfs_num, ans);
}

int main(){

  speedBoost;
  int C, S, Q;
  int numCases = 0;
  while((cin >> C >> S >> Q), (C || S || Q)){

    if(numCases) cout << "\n";
    cout << "Case #" << ++numCases << "\n";

    vector<edge> edges;
    AL.assign(C, vii());
    UnionFind UF(C);

    for(int i=0; i<S; i++){
      int c1, c2, d; cin >> c1 >> c2 >> d;
      c1--, c2--;
      edges.emplace_back(d, c1, c2);
    }

    sort(edges.begin(), edges.end());
    for(auto [w, u, v] : edges){
      if(!UF.isSameSet(u, v)){
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
        UF.unionSet(u, v);
      }
    }

    for(int i=0; i<Q; i++){
      int c1, c2; cin >> c1 >> c2;
      c1--, c2--;
      if(UF.isSameSet(c1, c2)){
        vi dfs_num(C, UNVISITED);
        int ans = 0;
        dfs(c1, c2, 0, dfs_num, ans);
        cout << ans << "\n";
      }
      else
        cout << "no path\n";
    }
  }

  return 0;
}
