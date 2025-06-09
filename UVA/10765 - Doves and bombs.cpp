#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

enum { UNVISITED = -1 };

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren, ConnectedComponent;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
  if(a.first == b.first)
    return a.second < b.second;
 return a.first > b.first;
}

void articulationPoint(int u){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;
      if(u == dfsRoot) rootChildren++;

      articulationPoint(v);

      if(dfs_low[v] >= dfs_num[u])
        articulation_vertex[u]++;  // add 1 every time an articulation point is detected here
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){

  int n, m;
  int a, b;
  while((cin >> n >> m), n, m){

    AL.assign(n, vi());
    dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0);
    dfs_parent.assign(n, -1);     articulation_vertex.assign(n, 0);
    dfsNumberCounter = 0, ConnectedComponent = 0;

    while((cin >> a >> b)){
      if(a == -1 && b == -1) break;

      AL[a].emplace_back(b);
      AL[b].emplace_back(a);
    }

    for(int u=0; u<n; u++){
      if(dfs_num[u] == UNVISITED){
        ConnectedComponent++;
        dfsRoot = u; rootChildren = 0;
        articulationPoint(u);
        articulation_vertex[dfsRoot] = (rootChildren > 1);
      }
    }

    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++)
      ans.push_back({articulation_vertex[i] + ConnectedComponent, i});

    sort(ans.begin(), ans.end(), compare);

    for(int i=0; i<m; i++)
      cout << ans[i].second << " " << ans[i].first << endl;
    cout << endl;
  }

  return 0;
}
