#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int g[27][27];
bool vis[27], used[27];
int inDeg[27], outDeg[27];

void dfs(int u){
  vis[u] = true;
  for(int v=0; v<26; v++)
    if(!vis[v] && g[u][v])
      dfs(v);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    // Assume the graph is undirected for
    // for checking connectivity
    memset(g, 0, sizeof g);
    memset(inDeg, 0, sizeof inDeg);
    memset(outDeg, 0, sizeof outDeg);
    memset(vis, false, sizeof vis);
    memset(used, false, sizeof used);

    int n; cin >> n;
    for(int i=0; i<n; i++){
      string s; cin >> s;
      int len = s.size();
      int a = s[0] - 'a', b = s[len-1] - 'a';
      g[a][b] = 1, g[b][a] = 1; // Undirected
      inDeg[b]++, outDeg[a]++;
      used[a] = used[b] = true;
    }

    int CC = 0;
    for(int i=0; i<26; i++)
      if(used[i] && !vis[i])
        CC++, dfs(i);

    if(CC > 1){ // Not connected
      cout << "The door cannot be opened.\n";
      continue;
    }

    int plusInDeg = 0, plusOutDeg = 0;
    bool hasEulerpath = true;
    for(int i=0; i<26 && hasEulerpath; i++){
      if(used[i]){ // Simple property check
        if(inDeg[i] == outDeg[i] + 1) plusInDeg++;
        else if(outDeg[i] == inDeg[i] + 1) plusOutDeg++;
        else if(inDeg[i] != outDeg[i]) { hasEulerpath = false; break; }
      }
    }

    if(!hasEulerpath){
      cout << "The door cannot be opened.\n";
      continue;
    }

    if((!plusInDeg && !plusOutDeg) || (plusInDeg == 1 && plusOutDeg == 1))
      cout << "Ordering is possible.\n";
    else
      cout << "The door cannot be opened.\n";
  }

  return 0;
}


