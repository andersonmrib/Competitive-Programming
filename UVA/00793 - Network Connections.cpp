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
  int t; cin >> t;
  string dummy;
  bool first = true;

  while(t--){

    int N; cin >> N; getline(cin, dummy);
    string command;

    UnionFind UF(N);
    int success = 0, unsuccess = 0;

    while(getline(cin, command)){

      if(command == "") break;
      stringstream ss(command);

      char op;
      int a, b;
      ss >> op >> a >> b;
      a--, b--;

      if(op == 'c'){
        UF.unionSet(a, b);
      }
      else if(op == 'q'){
        bool question = UF.isSameSet(a, b);
        if(question) success++;
        else         unsuccess++;
      }
    }

    cout << success << "," << unsuccess << "\n";
    if(t) cout << "\n";
  }

  return 0;
}
