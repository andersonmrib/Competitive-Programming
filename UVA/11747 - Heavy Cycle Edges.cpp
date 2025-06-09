#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
vector<iii> EL;

class UnionFind{

private:
  vi p, rank;

public:

  UnionFind(int N){
    p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
    rank.assign(N, 0);
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
  int n, m;
  while((cin >> n >> m), (n || m)){

    EL.assign(m, iii());
    for(int i=0; i<m; i++){
      int u, v, w; cin >> u >> v >> w;
      EL[i] = {w, u, v};
    }

    sort(EL.begin(), EL.end());

    int mst_cost = 0, num_taken = 0;
    UnionFind UF(n);
    vi ans;
    for(int i=0; i<m; i++){
      auto [w, u, v] = EL[i];
      if(UF.isSameSet(u, v)){
        ans.push_back(w);
        continue;
      }
      else UF.unionSet(u, v);
    }

    if(ans.size() == 0){
      cout <<"forest\n";
      continue;
    }

    sort(ans.begin(), ans.end());
      for(int i=0; i<ans.size(); i++){
        if(i == 0) cout << ans[i];
        else       cout << " " << ans[i];
      }
      cout << "\n";
  }

  return 0;
}
