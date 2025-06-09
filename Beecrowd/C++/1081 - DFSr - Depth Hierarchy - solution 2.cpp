#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define MAX 21
int adj[MAX][MAX];
int visited[MAX];

string printPath(int u, int v, string indent){
  cout << indent << u << "-" << v;
  if(visited[v]) cout << " pathR(G," << v << ")";

  return "";
}


int dfs(int u, string indent){
  int found = 0;
  for(int v=0; v<MAX; v++){
    if(adj[u][v] == 1){
        cout << printPath(u, v, indent) << endl;
        adj[u][v] = 0;
        if(visited[v]){
           visited[v] = 0;
           dfs(v, indent + "  ");
        }
        found = 1;
     }
   }
  return found;
}

int main(){

  int numCases = 0;
  int n;
  cin >> n;
  while(n--){

    cout << "Caso " << ++numCases << ":" << endl;

    memset(adj, 0, sizeof(adj));
    memset(visited, 1, sizeof(visited));

    int v, e; cin >> v >> e;

    for(int u=0; u<e; u++){
      int u1, u2;
      cin >> u1 >> u2;
      adj[u1][u2] = 1;
    }

    for(int u=0; u<v; u++){
      visited[u] = 0;
      if(dfs(u, "  "))
        cout << endl;
    }
  }

  return 0;
}
