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

  vi dist(n, INF), par(n, -1);
  dist[0] = 0;
  queue<int> q; q.push(0);
  while(!q.empty()){

    int u = q.front(); q.pop();
    if(u == n-1) break;

    for(auto v : AL[u]){
      if(dist[v] == INF){
        par[v] = u;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
      else continue;
    }
  }

  if(par[n-1] != -1){
    cout << dist[n-1] + 1 << endl;
    vi path;
    for(int cur=n-1; cur != -1; cur=par[cur])
      path.push_back(cur+1);
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++){
      if(i > 0) cout << " ";
      cout << path[i];
    }
    cout << endl;
  }
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}
