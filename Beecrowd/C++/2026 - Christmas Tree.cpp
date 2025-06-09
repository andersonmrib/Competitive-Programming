#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_W = 310;

int P, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == P) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), V[id]+dp(id+1, remW-W[id]));
}

int main(){

  int G; scanf("%d", &G);
  int counter = 0;
  while(G--){
    printf("Galho %d:\n", ++counter);

    memset(memo, -1, sizeof memo);
    int WB; scanf("%d %d", &P, &WB);
    for(int i=0; i<P; i++)
      scanf("%d %d", &V[i], &W[i]);

    int ans = dp(0, WB);
    printf("Numero total de enfeites: %d\n\n", ans);
  }

  return 0;
}
