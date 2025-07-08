#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank, setSize;

public:

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0), setSize.assign(n, 1);
  }

  int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int sizeOfSet(int i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
    setSize[y] += setSize[x];
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int F; cin >> F;
    unordered_map<string, int> umap;
    UnionFind UF(2*F);
    int ctt = 0;
    for(int i=0; i<F; i++){
      string p1, p2; cin >> p1 >> p2;
      if(umap.find(p1) == umap.end())
        umap[p1] = ctt++;
      if(umap.find(p2) == umap.end())
        umap[p2] = ctt++;
      int a = umap[p1], b = umap[p2];
      UF.unionSet(a, b);
      cout << UF.sizeOfSet(a) << "\n";
    }
  }

  return 0;
}
