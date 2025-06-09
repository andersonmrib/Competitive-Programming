#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
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
  bool first = true;
  while(t--){

    if(!first) cout << "\n";
    first = false;

    int N; cin >> N;
    coordinates.clear();
    edges.clear();

    UnionFind UF(N);
    for(int i=0; i<N; i++){
      double x, y; cin >> x >> y;
      coordinates.push_back({x, y});
    }


    for(int i=0; i<N-1; i++){
      for(int j=i+1; j<N; j++){
        double a = coordinates[i].first, b = coordinates[i].second;
        double x = coordinates[j].first, y = coordinates[j].second;
        double dist = sqrt((x - a)*(x - a) + (y - b)*(y - b));
        edges.push_back({dist, i, j});
      }
    }

    sort(edges.begin(), edges.end());
    double sum = 0;
    int num_taken = 0;
    for(auto [w, u, v] : edges){
      if(UF.isSameSet(u, v)) continue;
      sum += w;
      UF.unionSet(u, v);
      if(num_taken == N-1) break;
    }

    printf("%.2lf\n", sum);
    if(t) printf("\n");
  }

  return 0;
}
