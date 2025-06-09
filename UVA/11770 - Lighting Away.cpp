#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num, S;

enum {UNVISITED = -1};

void kosaraju(int u){
  dfs_num[u] = 1;
  vi &neighbors = AL[u];
  for(auto v : neighbors)
    if(dfs_num[v] == UNVISITED)
      kosaraju(v);
  S.push_back(u);
}

int main(){

  speedBoost;
  int t; cin >> t;
  int k = 0;
  while(t--){

    int n, m; cin >> n >> m;

    AL.assign(n, vi());
    dfs_num.assign(n, UNVISITED), S.clear();

    for(int i=0; i<m; i++){
      int a, b; cin >> a >> b;
      a--, b--;
      AL[a].emplace_back(b);
    }

    for(int i=0; i<n; i++)
      if(dfs_num[i] == UNVISITED)
        kosaraju(i);

    dfs_num.assign(n, UNVISITED);
    int numSCC = 0;
    for(int u=n-1; u>=0; u--){
      if(dfs_num[S[u]] == UNVISITED)
        numSCC++, kosaraju(S[u]);
    }

    cout << "Case " << ++k << ": ";
    cout << numSCC << "\n";
  }

  return 0;
}
