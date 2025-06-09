#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

enum {UNVISITED = -1, VISITED = -2};

typedef vector<int> vi;
vector<vi> AL;

vi dfs_num;

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v:AL[u])
    if(dfs_num[v] == UNVISITED)
    dfs(v);
}

int main(){

  int n, m; cin >> n >> m;

  AL.assign(n+1, vi());
  dfs_num.assign(n+1, UNVISITED);

  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    AL[a].emplace_back(b);
    AL[b].emplace_back(a);
  }

  dfs(1);

  bool allConnected = true;
  for(int u=1; u<=n; u++){
    if(dfs_num[u] == UNVISITED){
      allConnected = false;
      cout << u << endl;
    }
  }

  if(allConnected) cout << "Connected" << endl;

  return 0;
}
