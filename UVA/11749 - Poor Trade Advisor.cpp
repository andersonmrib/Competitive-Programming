#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
vector<vector<ii>> AL;
vi dfs_num;

const int INF = INT_MAX;
enum {UNVISITED = -1, VISITED = -2};

int dfs(int u, int maxPPA){
  dfs_num[u] = VISITED;
  int CC = 1;
  for(auto [v, w] : AL[u]){
    if(dfs_num[v] == VISITED || w != maxPPA)
      continue;
    CC += dfs(v, maxPPA);
  }
  return CC;
}

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m)){

    if(n == 0 && m == 0) break;

    AL.assign(n, vector<ii>()); dfs_num.assign(n, UNVISITED);
    int maxPPA = -INF-1;

    for(int i=0; i<m; i++){
      int a, b, ppa; cin >> a >> b >> ppa;
      maxPPA = max(maxPPA, ppa);
      a--, b--;
      AL[a].emplace_back(b, ppa);
      AL[b].emplace_back(a, ppa);
    }

    int largestCC = 0;
    for(int i=0; i<n; i++){
      if(dfs_num[i] == UNVISITED)
        largestCC = max(largestCC, dfs(i, maxPPA));
    }

    cout << largestCC << "\n";
  }

  return 0;
}
