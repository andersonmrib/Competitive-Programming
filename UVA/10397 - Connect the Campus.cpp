#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
struct Edge{
  int u, v;
  double dist;
  bool operator<(const Edge &other) const{
    return dist < other.dist;
  }
};

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
  int n;
  while(cin >> n){

    UnionFind UF(n);
    vector<ii> coordinates;
    vector<Edge> edges;

    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      coordinates.push_back({x, y});
    }

    int num_taken = 0;
    int m; cin >> m;
    for(int i=0; i<m; i++){
      int a, b; cin >> a >> b; a--, b--;
      double dx = coordinates[b].first - coordinates[a].first;
      double dy = coordinates[b].second - coordinates[a].second;
      double dist = hypot(dx, dy);
      edges.push_back({a, b, dist});
      UF.unionSet(a, b);
    }

    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
        double dx = coordinates[j].first - coordinates[i].first;
        double dy = coordinates[j].second - coordinates[i].second;
        double dist = sqrt(dx*dx + dy*dy);
        edges.push_back({i, j, dist});
      }
    }

    sort(edges.begin(), edges.end());
    double ans = 0;
    for(auto [u, v, w] : edges){
      if(num_taken == n-1) break;
      if(UF.isSameSet(u, v)) continue;
      UF.unionSet(u, v);
      ans += w;
      num_taken++;
    }

    cout << fixed << setprecision(2);
    cout << ans << "\n";
  }

  return 0;
}
