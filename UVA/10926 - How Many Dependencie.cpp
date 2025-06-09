#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num, numDependencies;

enum {UNVISITED = -1, VISITED = -2};

void dfs(int u, int source){
  dfs_num[u] = VISITED;
  numDependencies[source]++;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED)
      dfs(v, source);
  }
}

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    AL.assign(n, vi()), numDependencies.assign(n, 0);
    for(int i=0; i<n; i++){
      int t; cin >> t;
      for(int j=0; j<t; j++){
        int b; cin >> b;
        AL[i].emplace_back(b-1);
      }
    }

    for(int i=0; i<n; i++){
      dfs_num.assign(n, UNVISITED);
      dfs(i, i);
    }

    int maxNumDep = 0, ansIndex = 0;
    for(int i=0; i<n; i++){
      if(numDependencies[i] > maxNumDep){
        maxNumDep = numDependencies[i];
        ansIndex = i;
      }
    }

    cout << ansIndex + 1 << "\n";
  }

  return 0;
}
