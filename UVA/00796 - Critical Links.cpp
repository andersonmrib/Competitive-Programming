#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AL;

vi dfs_num, dfs_low, dfs_parent;
vector<ii> links;
int dfsNumberCounter;

enum {UNVISITED = -1};

void findBridges(int u){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;

      findBridges(v);

      if(dfs_low[v] > dfs_num[u])
        links.push_back({min(u, v), max(u, v)});

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){

  // speedBoost;
  int N;
  while(cin >> N){

    cin.ignore();

    AL.assign(N, vi());
    dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0);
    dfs_parent.assign(N, -1); links.clear();
    dfsNumberCounter = 0;

    for(int i=0; i<N; i++){
      string line; getline(cin, line);
      stringstream ss(line);

      int u, v;
      ss >> u;
      ss >> line;
      while(ss >> v){
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
      }
    }

    for(int i=0; i<N; i++)
      sort(AL[i].begin(), AL[i].end());

    for(int u=0; u<N; u++){
      if(dfs_num[u] == UNVISITED)
        findBridges(u);
    }

    sort(links.begin(), links.end());
    cout << links.size() << " critical links\n";
    for(auto [u, v] : links)
      cout << u << " - " << v << "\n";
    cout << "\n";
  }

  return 0;
}
