#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num;

int fallen;

enum {UNVISITED = -1, VISITED = -2};

void dfs(int u){
  dfs_num[u] = VISITED;
  fallen++;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m, l; cin >> n >> m >> l;

    AL.assign(n, vi()); dfs_num.assign(n, UNVISITED);
    for(int i=0; i<m; i++){
      int x, y; cin >> x >> y;
      x--, y--;
      AL[x].emplace_back(y);
    }

    fallen = 0;
    for(int i=0; i<l; i++){
      int p; cin >> p; p--;
      if(dfs_num[p] == UNVISITED)
        dfs(p);
    }

    cout << fallen << "\n";
  }

  return 0;
}
