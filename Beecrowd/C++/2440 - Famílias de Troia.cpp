#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

enum { UNVISITED = -1, VISITED = -2 };

vi dfs_num; // going to use a vector of integer for the number of connected components

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
    dfs(v);
}

int main(){

  int m, n, u, v; cin >> n >> m;

  AL.assign(n+1, vi());
  for(int i=0; i<m; i++){
    cin >> u >> v;
    AL[u].emplace_back(v); // u to v or
    AL[v].emplace_back(u); // v to u it is the same in an undirected graph
  }

  int CC = 0; //Number of connect components
  dfs_num.assign(n+1, UNVISITED);
  for(int i=1; i<=n; i++)
    if(dfs_num[i] == UNVISITED)
      CC++, dfs(i);

  cout << CC << endl;

  return 0;
}
