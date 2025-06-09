#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

enum { UNVISITED = -1 };

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;   // dfs_low[u] <= dfs_num[u]
    for(auto v : AL[u]){
      if(dfs_num[v] == UNVISITED){                // a tree edge
        dfs_parent[v] = u;
        if(u == dfsRoot) rootChildren++;          // special case, root

        articulationPointAndBridge(v);

        if(dfs_low[v] >= dfs_num[u])              // found an articulation point
          articulation_vertex[u] = 1;             // stores it

        dfs_low[u] = min(dfs_low[u], dfs_low[v]); // always update subtree
      }
      else if(v != dfs_parent[u])                 // s non-trivial cycle
        dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update it
    }
}

int main(){

  int N, originVertex, x;
  string places;
  stringstream ss;
  while((cin >> N), N){
    cin.ignore();

    AL.assign(N, vi());
    dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0);
    dfs_parent.assign(N, -1);     articulation_vertex.assign(N, 0);
    dfsNumberCounter = 0;

    while(true){
      getline(cin, places);               // going to real all the numbers at once
      ss.clear();                         // do not forget to clear it

      ss << places;
      ss >> originVertex;                 // gets the first number (our primary vertex)

      if(originVertex == 0) break;        // simple check
      originVertex--;                     // do not forget we are working with 0-indexes style (1)

      while(ss >> x){
        x--;                              // same as (1)
        AL[originVertex].emplace_back(x);
        AL[x].emplace_back(originVertex);
      }
    }

    for(int u=0; u<N; u++)
    if(dfs_num[u] == UNVISITED){          // starts checking...
      dfsRoot = u; rootChildren = 0;
      articulationPointAndBridge(u);
      articulation_vertex[dfsRoot] = (rootChildren > 1); // this is a special case
    }

    cout << count(articulation_vertex.begin(), articulation_vertex.end(), 1) << endl;

  }

  return 0;
}
