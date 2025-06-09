#include <bits/stdc++.h>
using namespace std;

#define MAX 101
double AM[MAX][MAX];

int main(){

  int n;
  while((cin >> n), n){

    int m; cin >> m;

    for(int u=0; u<n; u++){
      for(int v=0; v<n; v++)
        AM[u][v] = 0;
      AM[u][u] = 1;
    }

    for(int i=0; i<m; i++){
      int u, v, p; cin >> u >> v >> p; u--, v--;
      AM[u][v] = p * 0.01;
      AM[v][u] = p * 0.01;
    }

    for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
          AM[i][j] = max(AM[i][j], AM[i][k] * AM[k][j]);

    printf("%.6lf percent\n", AM[0][n-1] * 100);
  }

  return 0;
}
