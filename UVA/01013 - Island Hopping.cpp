#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<tuple<double, int, int>> edges;
vector<tuple<int, int, int>> island;
vi peopleSum;

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
    peopleSum[y] += peopleSum[x];
  }
};

int main(){

  speedBoost;
  int n;
  int numCases = 0;
  while((cin >> n), n){

    edges.clear(), island.clear();
    peopleSum.assign(n, 0);
    long long sum = 0;

    for(int i=0; i<n; i++){
      int x, y, m; cin >> x >> y >> m;
      island.push_back({x, y, m});
      sum += m;
      peopleSum[i] = m;
    }

    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
        auto [a, b, c] = island[j];
        auto [x, y, z] = island[i];
        double dist = sqrt((a - x)*(a - x) + (b - y)*(b - y));
        edges.push_back({dist, i, j});
      }
    }

    UnionFind UF(n);
    sort(edges.begin(), edges.end());
    double mst_cost = 0;
    for(auto e : edges){
      auto [w, u, v] = e;
      if(UF.isSameSet(u, v)) continue;
      if(UF.isSameSet(u, 0))
        mst_cost += w*peopleSum[UF.findSet(v)];
      if(UF.isSameSet(v, 0))
        mst_cost += w*peopleSum[UF.findSet(u)];
      UF.unionSet(u, v);
    }

    printf("Island Group: %d Average %.2lf\n\n", ++numCases, mst_cost/sum);
  }

  return 0;
}
