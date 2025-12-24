#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

class UnionFind{

private:
  vi p, rank, setSize;
  int numSets, lasrgest;

public:

  UnionFind(int n){
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
    lasrgest = 0;
  }

  int findSet(int i){
    return (p[i] == i) ? i : p[i] = findSet(p[i]);
  }

  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }

  int numDiffSets(){
    return numSets;
  }

  int biggestOne(){
    return lasrgest;
  }

  void unionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[y] == rank[x])
      rank[y]++;
    setSize[y] += setSize[x];
    numSets--;
    lasrgest = max(lasrgest, max(setSize[x], setSize[y]));
  }
};

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  UnionFind UF(n);
  while(m--){

    int a, b; cin >> a >> b;
    a--, b--;
    UF.unionSet(a, b);
    cout << UF.numDiffSets() << " " << UF.biggestOne() << endl;
  }

  return 0;
}
