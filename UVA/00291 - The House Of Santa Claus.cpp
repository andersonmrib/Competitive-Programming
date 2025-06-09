#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int g[6][6];
int ans[9];

void dfs(int u, int idx){
  ans[idx] = u;
  if(idx == 8){
    for(int i=0; i<=8; i++)
      cout << ans[i];
    cout << "\n";
    return;
  }

  for(int v=1; v<=5; v++){
    if(g[u][v] == 1){
      g[u][v] = g[v][u] = 0;
      dfs(v, idx+1);
      g[u][v] = g[v][u] = 1;
    }
  }
}

int main(){

  speedBoost;
  memset(g, 0, sizeof g);
  memset(ans, 0, sizeof ans);
  g[1][2] = g[2][1] = 1;
  g[1][3] = g[3][1] = 1;
  g[1][5] = g[5][1] = 1;
  g[2][3] = g[3][2] = 1;
  g[2][5] = g[5][2] = 1;
  g[3][5] = g[5][3] = 1;
  g[3][4] = g[4][3] = 1;
  g[5][4] = g[4][5] = 1;

  dfs(1, 0);

  return 0;
}
