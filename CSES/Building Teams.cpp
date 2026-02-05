#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

vector<vi> AL;

int main(){

  speedBoost;

  int n, m; cin >> n >> m;
  AL.assign(n, vi());
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    AL[b].push_back(a);
  }

  bool isBipartite = true;
  vi color(n, INF);
  queue<int> q;
  for(int k=0; k<n; k++){

    if(color[k] != INF) continue;

    color[k] = 0;
    q.push(k);

    while(!q.empty()){
      int u = q.front(); q.pop();
      for(auto v : AL[u]){
        if(color[v] == color[u]){
          isBipartite = false;
          break;
        }
        if(color[v] == INF){
          color[v] = 1 - color[u];
          q.push(v);
        }
      }
      if(!isBipartite) break;
    }
  }

  if(isBipartite){
    for(int i=0; i<n; i++){
      if(i > 0) cout << " ";
      cout << color[i] + 1;
    }
    cout << endl;
  }
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}
