#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
  vi p, rank, setSize;
  int maxPeople;

public:

  UnionFind(int N){
    p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
    rank.assign(N, 0);
    setSize.assign(N, 1);
    maxPeople = 1;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int giveMeTheAnswer() { return maxPeople; }

  void UnionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) rank[y]++;
    setSize[y] += setSize[x];
    maxPeople = max(maxPeople, setSize[y]);
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int N, M; cin >> N >> M;

    UnionFind UF(N);

    for(int i=0; i<M; i++){
      int A, B; cin >> A >> B;
      A--, B--;
      UF.UnionSet(A, B);
    }

    cout << UF.giveMeTheAnswer() << "\n";
  }

  return 0;
}
