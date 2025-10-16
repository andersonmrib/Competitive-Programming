#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

vector<bool> vis;

void dfs(int u){
  vis[u] = true;
  for(auto v : AL[u])
    if(vis[v] == false)
      dfs(v);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    vector<string> edges;
    string line;
    while(cin >> line){
      if(line[0] == '*') break;
      edges.push_back(line);
    }

    cin >> line;
    int V = 0;
    vi map(26, -1);
    for(auto c : line){
      if(c >= 'A' && c <= 'Z')
        if(map[c - 'A'] == -1)
           map[c - 'A'] = V++;
    }

    AL.assign(V, vi());
    for(auto e : edges){
      int u = map[e[1] - 'A'];
      int v = map[e[3] - 'A'];
      AL[u].emplace_back(v);
      AL[v].emplace_back(u);
    }

    vis.assign(V, false);
    int trees = 0;
    for(auto u=0; u<V; u++){
      if(vis[u] == false)
        trees++, dfs(u);
    }

    int acorns = 0;
    for(int u=0; u<V; u++)
      if(AL[u].empty())
        acorns++;

    cout << "There are ";
    cout << trees - acorns;
    cout << " tree(s) and ";
    cout << acorns;
    cout << " acorn(s).\n";
  }

  return 0;
}
