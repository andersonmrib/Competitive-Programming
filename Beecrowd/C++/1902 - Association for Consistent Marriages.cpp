#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num, dfs_parent;
int ans;

enum {UNVISITED = -1, EXPLORED = -2, VISITED = -3};

void cycleCheck(int u){
  dfs_num[u] = EXPLORED;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;
      cycleCheck(v);
    }
    else if(dfs_num[v] == EXPLORED){
      if(v == dfs_parent[u]) // Bidirectional edge
        ans++;
      else                   // Back edge
        ans++;
    }
  }
  dfs_num[u] = VISITED;
}

int main(){

  speedBoost;
  unordered_map<string, int> umap;

  string name1, name2;
  int counter = 0, numPeople = 0;
  vi track;
  while(cin >> name1 >> name2){
    int a, b;
    if(umap.find(name1) == umap.end()){
      umap[name1] = counter++;
      numPeople++;
    }
    a = umap[name1];
    if(umap.find(name2) == umap.end()){
      umap[name2] = counter++;
      numPeople++;
    }
    b = umap[name2];
    track.push_back(a), track.push_back(b);
  }

  AL.assign(numPeople, vi());
  dfs_num.assign(numPeople, UNVISITED); dfs_parent.assign(numPeople, 0);

  for(int i=0; i<track.size(); i+=2)
    AL[track[i]].emplace_back(track[i+1]);

  ans = 0;
  for(int i=0; i<numPeople; i++)
    if(dfs_num[i] == UNVISITED)
      cycleCheck(i);

  cout << ans << "\n";

  return 0;
}
