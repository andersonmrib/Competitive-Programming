#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int g[500][500];
bool adj[500][500];
vector<int> dfs_num;

const int INF = 1e9;
enum { UNVISITED = -1, VISITED = -2 };
int p, r;

void dfs(int u){
  dfs_num[u] = VISITED;
  for(int v=1; v<=p; v++)
    if(adj[u][v] && dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  speedBoost;
  int NC = 0;
  while((cin >> p >> r), (p || r)){

    dfs_num.assign(p+1, UNVISITED);
    memset(g, 0, sizeof g);
    memset(adj, 0, sizeof adj);
    unordered_map<string, int> umap;

    for(int i=1; i<=p; i++){
      for(int j=1; j<=p; j++)
        g[i][j] = INF;
      g[i][i] = 0;
    }

    int counter = 1;
    for(int i=0; i<r; i++){
      string n1, n2; cin >> n1 >> n2;
      if(umap.find(n1) == umap.end()) umap[n1] = counter++;
      if(umap.find(n2) == umap.end()) umap[n2] = counter++;
      int a = umap[n1], b = umap[n2];
      g[a][b] = g[b][a] = 1;
      adj[a][b] = adj[b][a] = true;
    }

    int CC = 0;
    for(int i=1; i<=p; i++)
      if(dfs_num[i] == UNVISITED)
        CC++, dfs(i);

    cout << "Network " << ++NC << ": ";
    if(CC > 1){
      cout << "DISCONNECTED\n\n";
      continue;
    }

    for(int k=1; k<=p; k++)
      for(int i=1; i<=p; i++)
        for(int j=1; j<=p; j++)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int ans = -1;
    for(int i=1; i<=p; i++)
      for(int j=1; j<=p; j++)
        ans = max(ans, g[i][j]);

    cout << ans << "\n\n";
  }

  return 0;
}
