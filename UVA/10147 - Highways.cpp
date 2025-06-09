#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AL;

vii coordinates;
vector<tuple<double, int, int>> edges;

class UnionFind{

private:
  vi p, rank;

public:

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int N; cin >> N;
    coordinates.clear();
    edges.clear();

    for(int i=0; i<N; i++){
      int x, y; cin >> x >> y;
      coordinates.push_back({x, y});
    }

    int M; cin >> M;
    UnionFind UF(N);
    for(int i=0; i<M; i++){
      int u, v; cin >> u >> v;
      u--, v--;
      UF.unionSet(u, v);
    }

    for(int i=0; i<N-1; i++){
      for(int j=i+1; j<N; j++){
        int a = coordinates[i].first, b = coordinates[i].second;
        int x = coordinates[j].first, y = coordinates[j].second;
        double dist = sqrt((x - a)*(x - a) + (y - b)*(y - b));
        edges.push_back({dist, i, j});
      }
    }

    sort(edges.begin(), edges.end());
    vector<ii> ans;
    for(auto [w, u, v] : edges){
      if(!UF.isSameSet(u, v)){
        UF.unionSet(u, v);
        ans.push_back({u, v});
      }
    }
    if(ans.empty())
      cout << "No new highways need\n";
    else
      for(auto [u, v] : ans)
        cout << u+1 << " " << v+1 << "\n";

      if(t) cout << "\n";
  }

  return 0;
}
