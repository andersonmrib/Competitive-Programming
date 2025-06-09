#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

vi dfs_num, toposort;
enum {UNVISITED = 1, VISITED = -2};

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
  toposort.push_back(u);
}

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m), (n || m)){

    AL.assign(n, vi());
    dfs_num.assign(n, UNVISITED);
    toposort.clear();

    for(int i=0; i<m; i++){
      int a, b; cin >> a >> b;
      a--, b--;
      AL[a].emplace_back(b);
    }

    for(int i=0; i<n; i++)
      if(dfs_num[i] == UNVISITED)
        dfs(i);

    reverse(toposort.begin(), toposort.end());
    for(int i=0; i<toposort.size(); i++){
      if(i > 0) cout << " " << toposort[i] + 1;
      else      cout << toposort[i] + 1;
    }
    cout << "\n";
  }

  return 0;
}
