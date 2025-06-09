#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num;

enum { UNVISITED = -1, VISITED = -2 };

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  int t; cin >> t;
  int numCases = 0;
  while(t--){
    int n, m; cin >> n >> m;

    AL.assign(n, vi()), dfs_num.assign(n, UNVISITED);

    for(int i=0; i<m; i++){
      int x, y; cin >> x >> y; x--, y--;
      AL[x].emplace_back(y);
      AL[y].emplace_back(x);
    }

    int CC = 0;
    for(int u=0; u<n; u++)
      if(dfs_num[u] == UNVISITED)
        CC++, dfs(u);

    if(CC == 1) printf("Caso #%d: a promessa foi cumprida\n", ++numCases);
    else        printf("Caso #%d: ainda falta(m) %d estrada(s)\n", ++numCases, CC-1);
  }

  return 0;
}
