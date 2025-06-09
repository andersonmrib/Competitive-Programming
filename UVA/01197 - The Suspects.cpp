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
    rank.assign(n, 0);
    setSize.assign(n, 1);
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numSet(int i) {return setSize[findSet(i)]; }

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
  int n, m;
  while((cin >> n >> m), (n || m)){

    UnionFind UF(n);

    for(int i=0; i<m; i++){
      int k; cin >> k;
      for(int j=0; j<k; j++){
        int previous, x;
        if(j == 0) cin >> previous;
        else{
          cin >> x;
          UF.unionSet(previous, x);
          previous = x;
        }
      }
    }

    cout << UF.numSet(0) << "\n";
  }

  return 0;
}
