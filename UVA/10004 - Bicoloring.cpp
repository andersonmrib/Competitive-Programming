#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

int main(){

  int n;
  while(cin >> n, n){
    vector<vi> AL(n, vi());
    int l; cin >> l;
    while(l--){
      int a, b; cin >> a >> b;
      AL[a].push_back(b);
      AL[b].push_back(a);
    }
    int s = 0;                         // initial vertex for BFS

    queue<int> q; q.push(s);
    vi color(n, INF); color[s] = 0;
    bool isBipartite = true;
    while(!q.empty() && isBipartite){
      int u = q.front(); q.pop();
      for(auto v : AL[u]){
        if(color[v] == INF){
           color[v] = 1-color[u];      // we are not going to record distance, just
           q.push(v);                  // the colors
        }
        else if(color[v] == color[u]){ // u and v with the same color
           isBipartite = false;        // false statement +
           break;                      // break for additional speedup
        }
      }
    }
    isBipartite ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
  }

  return 0;
}
