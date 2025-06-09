#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<pair<int, int>> people;
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

    int n; cin >> n;
    people.clear(), edges.clear();
    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      people.push_back({x, y});
    }

    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
        auto [a, b] = people[i];
        auto [x, y] = people[j];
        double dist = sqrt((a - x)*(a - x) + (b - y)*(b - y));
        edges.push_back({dist, i, j});
      }
    }

    double mst_cost = 0;
    int num_taken = 0;
    UnionFind UF(n);
    sort(edges.begin(), edges.end());
    
    // Kruskal's algorithm
    for(auto [w, u, v] : edges){
      if(UF.isSameSet(u, v)) continue;
      mst_cost += w;
      UF.unionSet(u, v);
      num_taken++;
      if(num_taken == n-1) break;
    }
    printf("%.2lf\n", mst_cost/100.0);
  }

  return 0;
}
