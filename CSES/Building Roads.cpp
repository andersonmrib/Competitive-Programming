#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num;

enum {VISITED = -1, UNVISITED = -2};

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  speedBoost;
  int n, m; cin >> n >> m;

  AL.assign(n, vi());
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    AL[b].push_back(a);
  }

  dfs_num.assign(n, UNVISITED);
  int numCC = 0;
  vi edges;
  for(int i=0; i<n; i++){
    if(dfs_num[i] == UNVISITED)
      numCC++, edges.push_back(i), dfs(i);
  }

  cout << numCC - 1 << endl;
  for(int i=1; i<edges.size(); i++)
    cout << edges[0] + 1 << " " << edges[i] + 1 << endl;

  return 0;
}
