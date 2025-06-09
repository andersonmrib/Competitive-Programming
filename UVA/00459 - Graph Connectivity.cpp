#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

enum {UNVISITED = -1, VISITED = -2};
vector<vi> AL;
vi dfs_num;

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy); // gets blank line
  bool first = true;

  while(t--){

    if(!first) cout << "\n";
    first = false;

    char maxNode; cin >> maxNode;
    getline(cin, dummy);

    int numNodes = maxNode - 'A' + 1;
    AL.assign(numNodes, vi());
    dfs_num.assign(numNodes, UNVISITED);

    string input;
    while(getline(cin, input) && !input.empty()){
      int a = input[0] - 'A', b = input[1] - 'A';
      AL[a].emplace_back(b);
      AL[b].emplace_back(a);
    }

    int ans = 0;
    for(int u=0; u<numNodes; u++)
      if(dfs_num[u] == UNVISITED){
      dfs(u); ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
