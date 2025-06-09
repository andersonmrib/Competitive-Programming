#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
const int INF = 1e9;


int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    AL.assign(n+1, vi());
    for(int i=1; i<=n; i++){
      int p; cin >> p;
      for(int j=1; j<=p; j++){
        int enemy; cin >> enemy;
        if(enemy > n) continue;
        AL[i].push_back(enemy);
        AL[enemy].push_back(i);
      }
    }

    int ans = 0;
    vi color(n+1, INF);
    for(int i=1; i<=n; i++){
      if(color[i] != INF) continue;
      bool isBipartite = true;
      int count0 = 1, count1 = 0;
      vi visited;

      queue<int> q;
      q.push(i);
      visited.push_back(i);
      color[i] = 0;

      while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : AL[u]){
          if(color[v] == INF){
            color[v] = 1 - color[u];
            visited.push_back(v);
            if(color[v] == 0) count0++;
            else              count1++;
            q.push(v);
          }
          else if(color[v] == color[u])
            isBipartite = false;
        }
      }
      if(!isBipartite){
        for(auto x : visited) color[x] = -INF;
          continue;
      }
      ans += max(count0, count1);
    }
    cout << ans << "\n";
  }

  return 0;
}


