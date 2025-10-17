#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank;
  int numSets;

public:
  int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int getNumSets() { return numSets; }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
    numSets--;
  }

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
    numSets = n;
  }
};

int main(){

  // speedBoost;
  int n, m;
  int NC = 1;
  while(scanf("%d %d", &n, &m), n || m){

    UnionFind UF(n);
    for(int i=0; i<m; i++){
      int a, b; scanf("%d %d", &a, &b);
      a--, b--;
      UF.unionSet(a, b);
    }

    printf("Case %d: ", NC++);
    printf("%d\n", UF.getNumSets());
  }

  return 0;
}
