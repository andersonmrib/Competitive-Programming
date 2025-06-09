#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

class UnionFind{

private:
  vi p, rank, setSize;
  vll sum;

public:

    UnionFind(int n){
      p.assign(2*n+1, 0); for(int i=1, j=i+n; i<=n; i++, j++){ p[i] = j; p[j] = j; }
      rank.assign(2*n+1, 0);
      setSize.assign(2*n+1, 1);
      sum.assign(2*n+1, 0); for(int i=1, j=i+n; i<=n; i++, j++) sum[j] = i;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int getSizeSet(int i) { return setSize[findSet(i)]; }
    ll getSumSet(int i) { return  sum[findSet(i)]; }

    void unionSet(int i, int j){
      if(isSameSet(i, j)) return;
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if(rank[x] == rank[y]) rank[y]++;
      setSize[y] += setSize[x];
      sum[y] += sum[x];
    }

    void move(int i, int j){
      if(isSameSet(i, j)) return;
      int w = findSet(i), y = findSet(j);
      setSize[w]--; setSize[y]++;
      sum[w] -= i; sum[y] += i;
      p[i] = y;
    }
};

int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    UnionFind UF(n);
    for(int i=0; i<m; i++){
      int command, p, q; cin >> command;

      if(command == 1){
        cin >> p >> q;
        UF.unionSet(p, q);
      }

      else if(command == 2){
        cin >> p >> q;
        UF.move(p, q);
      }

      else{
        cin >> p;
        cout << UF.getSizeSet(p) << " " << UF.getSumSet(p) << "\n";
      }
    }
  }

  return 0;
}
