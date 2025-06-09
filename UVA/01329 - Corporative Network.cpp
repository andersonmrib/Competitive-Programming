#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank, dist;

public:

  UnionFind(int N){
    p.assign(N+1, 0); for(int i=1; i<=N; i++) p[i] = i;
    rank.assign(N+1, 0);
    dist.assign(N+1, 0);
  }

  int findSet(int i){
    if(p[i] == i) return i;
    else{
      int root = findSet(p[i]);
      dist[i] += dist[p[i]];
      return p[i] = root;
    }
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int getDist(int i) { return dist[i]; }
  void changeDist(int i, int x){ dist[i] = x; }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[i] = j;
    if(rank[x] == rank[y]) rank[y]++;
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int N; cin >> N;
    UnionFind UF(N);

    char op;
    int I, J;
    while(cin >> op){

      if(op == 'O') break;

      if(op == 'E'){
        cin >> I;
        UF.findSet(I);
        cout << UF.getDist(I) << "\n";
      }
      else{
        cin >> I >> J;
        UF.unionSet(I, J);
        UF.changeDist(I, abs(I - J)%1000);
      }
    }
  }

  return 0;
}
