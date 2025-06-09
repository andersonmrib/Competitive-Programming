#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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

int main(){

  speedBoost;
  int N; cin >> N;
  while(N--){

    int S, P; cin >> S >> P;

    edges.clear();
    coordinates.clear();
    for(int i=0; i<P; i++){
      int x, y; cin >> x >> y;
      coordinates.push_back({x, y});
    }

    for(int i=0; i<P-1; i++){
      for(int j=i+1; j<P; j++){
        int x = coordinates[i].first, y = coordinates[i].second;
        int a = coordinates[j].first, b = coordinates[j].second;
        double dist = sqrt((x - a)*(x - a) + (y - b)*(y - b));
        edges.push_back({dist, i, j});
      }
    }

    sort(edges.begin(), edges.end());
    UnionFind UF(P);

    int num_taken = 0;
    int avaiable = P-S;
    // The satellites works as a free connection between
    // two points, helping us to construct the MTS using
    // the cheapest way
    double ans;
    for(auto [w, u, v] : edges){

      if(UF.isSameSet(u, v)) continue;
      ans = w;
      UF.unionSet(u, v);
      num_taken++;
      if(num_taken == avaiable) break;
    }

    cout << fixed << setprecision(2);
    cout << ans << "\n";
  }

  return 0;
}
