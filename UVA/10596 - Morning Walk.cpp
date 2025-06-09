#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num;

enum {UNVISITED = -1, VISITED = -2};

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

bool check(){

  for(int i=0; i<dfs_num.size(); i++)
    if(AL[i].size()&1) return false;   // can't be odd

  for(int i=0; i<dfs_num.size(); i++)
      if(!AL[i].size()) dfs_num[i] = VISITED; // removes isolated vertices

  int neighbor = -1;
  for(int i=0; i<dfs_num.size(); i++)
    if(dfs_num[i] == UNVISITED){
      neighbor = i;
      break;
    }

  if(neighbor > -1) dfs(neighbor);
  for(int x : dfs_num)
    if(x == UNVISITED) return false;
  return true;
}


int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    AL.assign(n, vi()), dfs_num.assign(n, UNVISITED);
    for(int i=0; i<m; i++){
      int a, b; cin >> a >> b;
      AL[a].emplace_back(b);
      AL[b].emplace_back(a);
    }

    if (check() && m)
      cout << "Possible\n";
    else
      cout << "Not Possible\n";
  }

  return 0;
}
