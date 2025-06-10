#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;
int g1[105][105], g2[105][105];

int main(){

  speedBoost;
  int P, R, BH, OF, YH, M;
  while(cin >> P >> R >> BH >> OF >> YH >> M){

    for(int i=1; i<=P; i++){
      for(int j=1; j<=P; j++)
        g1[i][j] = g2[i][j] = INF;
      g1[i][i] = g2[i][i] = 0;
    }

    for(int i=0; i<R; i++){
      int u, v, w; cin >> u >> v >> w;
      g1[u][v] = g1[v][u] = w;
      g2[u][v] = g2[v][u] = w;
    }

    for(int k=1; k<=P; k++)
      for(int i=1; i<=P; i++)
        for(int j=1; j<=P; j++)
          g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);

    for(int i=1; i<=P; i++)
      if(g1[BH][i] + g1[i][OF] == g1[BH][OF])
        for(int j=1; j<=P; j++)
          g2[i][j] = g2[j][i] = INF;

    for(int k=1; k<=P; k++)
      for(int i=1; i<=P; i++)
        for(int j=1; j<=P; j++)
          g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);

    if(g2[YH][M] == INF) cout << "MISSION IMPOSSIBLE.\n";
    else                  cout << g2[YH][M] << "\n";
  }

  return 0;
}
