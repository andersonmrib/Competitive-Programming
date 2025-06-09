#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank;

public:

  UnionFind(int N){
    p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
    rank.assign(N, 0);
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
  int N, Q; cin >> N >> Q;

  UnionFind UF(N);

  for(int i=0; i<Q; i++){

    char op;
    int a, b;

    cin >> op >> a >> b;

    if(op == '=') UF.unionSet(a, b);
    else cout << (UF.isSameSet(a, b) ? "yes\n" : "no\n");
  }

  return 0;
}
