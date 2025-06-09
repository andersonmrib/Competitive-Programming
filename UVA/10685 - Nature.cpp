#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank, setSize;
  int numMax;

public:

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numMax = 1;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numSet(int i) { return setSize[findSet(i)]; }
  int giveMeTheAnswer() { return numMax; }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
    setSize[y] += setSize[x];
    numMax = max(numMax, setSize[y]);
  }
};

int main(){

  speedBoost;
  int C, R;
  while((cin >> C >> R), (C || R)){

    UnionFind UF(C);

    unordered_map<string, int> umap;
    int counter = 0;
    for(int i=0; i<C; i++){
      string creature; cin >> creature;
      umap[creature] = counter;
      counter++;
    }

    for(int i=0; i<R; i++){
      string prey, predator; cin >> prey >> predator;
      int x = umap[prey], y = umap[predator];
      UF.unionSet(x, y);
    }

    cout << UF.giveMeTheAnswer() << "\n";
  }

  return 0;
}
