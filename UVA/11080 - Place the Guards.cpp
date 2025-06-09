#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
const int INF = 1e9;

int main(){

  speedBoost;
  int T; cin >> T;
  while(T--){
    int v, e; cin >> v >> e;

    AL.assign(v, vi());
    for(int i=0; i<e; i++){
      int f, t; cin >> f >> t;
        AL[f].emplace_back(t);
        AL[t].emplace_back(f);
    }

  vi color(v, INF);
  bool isBipartite = true;
  int ans = 0;

  for(int i=0; i<v; i++){
    if(color[i] == INF){
      queue<int> q;
      int color0 = 0, color1 = 0;
      q.push(i); color[i] = 0;  color0++;

      while(!q.empty() && isBipartite){
        int u = q.front(); q.pop();
        for(auto v : AL[u]){
          if(color[v] == INF){
            color[v] = 1 - color[u];
            if(color[v] == 0) color0++;
            else              color1++;
            q.push(v);
          }
          else if(color[v] == color[u]){
            isBipartite = false;
            break;
          }
        }
      }
      if(!isBipartite) break;
      ans += max(1, min(color0, color1));
    }
  }

  if(isBipartite) cout << ans << "\n";
  else            cout << -1 << "\n";
  }

  return 0;
}
