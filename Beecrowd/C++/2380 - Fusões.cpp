#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;

class UnionFind {
  private:
    vi p, rank, setSize;
    int numSets;
  public:
    UnionFind(int N){
      p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
      rank.assign(N, 0);
      setSize.assign(N, 1);
      numSets = N;
    }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
int isSameSet(int i, int j) { return findSet(i) == findSet(j); }

void unionSet(int i, int j){
  if(isSameSet(i, j)) return;
  int x = findSet(i), y = findSet(j);
  if(rank[x] > rank[y]) swap(x, y);
  p[x] = y;
  if(rank[x] == rank[y]) rank[y]++;
  setSize[y] += setSize[x];
  --numSets;
 }
};

int main(){

  int n, b; cin >> n >> b;
  char op;
  int c1, c2;

  UnionFind UF(n+1);
  while(b--){
    cin >> op >> c1 >> c2;
    if(op == 'F') UF.unionSet(c1, c2);
    else{
        if(UF.isSameSet(c1, c2)) cout << "S" << endl;
        else                     cout << "N" << endl;
    }
  }

  return 0;
}
