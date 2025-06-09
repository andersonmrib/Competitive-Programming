#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AL;
vector<ii> visited;

ii dfs(int u){
  int ans = 0, destination = 0;
  if(!AL[u].size()) return {0, u};
  if(visited[u].first != -1) return visited[u];
  for(auto v : AL[u]){
    auto [len, neighbor] = dfs(v);
    if(len + 1 > ans){
      ans = len + 1;
      destination = neighbor;
    }
    else if(len + 1 == ans && neighbor < destination)
      destination = neighbor;
  }
  visited[u] = {ans, destination};
  return {ans, destination};
}

int main(){

  speedBoost;
  int n;
  int NC = 0;
  while((cin >> n), n){

    AL.assign(n+1, vi());
    visited.assign(n+1, {-1, -1});

    int s; cin >> s;
    int p, q;
    while((cin >> p >> q), (p || q))
      AL[p].emplace_back(q);

    auto [len, dest] = dfs(s);
    cout << "Case " << ++NC << ": The longest path from " << s
     << " has length " << len << ", finishing at " << dest << ".\n\n";
  }

  return 0;
}
