#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
const int INF = 1e9;

int main(){

  speedBoost;
  int NC;
  int numCases = 0;
  while((cin >> NC), NC){

    unordered_map<int, int> mapper;
    int counter = 0;
    AL.assign(1000, vi());

    for(int i=0; i<NC; i++){
      int a, b; cin >> a >> b;
      if(mapper.find(a) == mapper.end()) { mapper[a] = counter++; }
      if(mapper.find(b) == mapper.end()) { mapper[b] = counter++; }
      AL[mapper[a]].emplace_back(mapper[b]);
      AL[mapper[b]].emplace_back(mapper[a]);
    }

    int source, TTL;
    while((cin >> source >> TTL), (source || TTL)){
      vi dist(counter, INF); queue<int> q;
      dist[mapper[source]] = 0; q.push(mapper[source]);

      bool stop = false;
      while(!q.empty() && !stop){
        int u = q.front(); q.pop();
        for(auto v : AL[u]){
          if(dist[v] == INF){
            dist[v] = dist[u] + 1;
            if(dist[v] > TTL){
              stop = true;
              break;
            }
            q.push(v);
          }
        }
      }

      int unreachable = 0;
      for(auto x : dist)
        if(x == INF || x > TTL) unreachable++;
      cout << "Case " << ++numCases << ": " << unreachable << " nodes not reachable from node " << source <<
      " with TTL = " << TTL << ".\n";
    }
  }

  return 0;
}
