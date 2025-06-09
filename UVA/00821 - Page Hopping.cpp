#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;

int main(){

  int a, b;
  int NC = 0;
  while((scanf("%d %d", &a, &b)), (a || b)){

    vector<vector<int>> AM(101, vector<int>(101, INF));
    int MAX_N = INT_MIN;
    do{
      a--, b--;
      AM[a][b] = 1;
      MAX_N = max(MAX_N, max(a, b));
    } while((scanf("%d %d", &a, &b)), (a || b));

    for(int k=0; k<=MAX_N; k++){
      for(int u=0; u<=MAX_N; u++){
        for(int v=0; v<=MAX_N; v++){
          AM[u][v] = min(AM[u][v], AM[u][k]+AM[k][v]);
        }
      }
    }

    int sum = 0, ctt = 0;
    for(int i=0; i<=MAX_N; i++){
      for(int j=0; j<=MAX_N; j++){
        if(i != j && AM[i][j] != INF)
          ctt++, sum += AM[i][j];
      }
    }

    printf("Case %d: average length between pages = %.3f clicks\n",++NC, (double)sum/ctt);
  }

  return 0;
}
