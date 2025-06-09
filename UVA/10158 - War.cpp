#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
int n;

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
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
  }
};

int main(){

  speedBoost;
  cin >> n;
  UnionFind UF(n*2);

  int c, x, y;
  while((cin >> c >> x >> y), (c || x || y)){

    if(c == 1){
      if(UF.isSameSet(x+n, y) || UF.isSameSet(x, y+n))
        cout << -1 << "\n";
      else
        UF.unionSet(x, y), UF.unionSet(x+n, y+n);
    }

    else if(c == 2){
      if(UF.isSameSet(x, y)) cout << -1 << "\n";
      else
        UF.unionSet(x+n, y), UF.unionSet(x, y+n);
    }
    else if(c == 3){
      if(UF.isSameSet(x, y)) cout << 1 << "\n";
      else                   cout << 0 << "\n";
    }
    else if(c == 4){
      if(UF.isSameSet(x, y+n)) cout << 1 << "\n";
      else                     cout << 0 << "\n";
    }
  }

  return 0;
}
