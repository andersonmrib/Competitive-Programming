#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int g[60][60], deg[60];
void dfs(int u){
  for(int i=1; i<=50; i++){
    if(g[u][i]){
      g[u][i]--, g[i][u]--;
      dfs(i);
      printf("%d %d\n", i, u);
    }
  }
}

int main(){

  int t; scanf("%d", &t);
  int NC = 0;
  while(t--){

    memset(g, 0, sizeof g);
    memset(deg, 0, sizeof deg);

    int n; scanf("%d", &n);
    int start;
    for(int i=0; i<n; i++){
      int a, b; scanf("%d %d", &a, &b);
      deg[a]++, deg[b]++;
      g[a][b]++, g[b][a]++;
      start = a;
    }

    bool skip = false;
    printf("Case #%d\n", ++NC);
    for(int i=1; i<=50 && !skip; i++){
      if(deg[i]&1){
        printf("some beads may be lost\n");
        skip = true;;
      }
    }

    if(skip){
      printf("\n");
      continue;
    }

    dfs(start);
    printf("\n");
  }

  return 0;
}
