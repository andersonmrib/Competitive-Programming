#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

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
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
  }
};

struct edge{
  int a, b;
  int weight;
};

bool cmp(edge a, edge b){
  return a.weight < b.weight;
}

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  vector<edge> edges;
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    edges.push_back({a, b, c});
  }

  sort(edges.begin(), edges.end(), cmp);
  UnionFind UF(n);
  int cost = 0, used = 0;
  for(auto [a, b, c] : edges){
    if(UF.isSameSet(a, b)) continue;
    UF.unionSet(a, b);
    cost += c;
    used++;
  }

  if(used == n-1)
    cout << cost << endl;
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}

