#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 60;
const int MAX_W = 110;

int N, power[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == N) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;                     // computed before
  if(W[id] > remW) return ans = dp(id+1, remW); // drop this, find another
  return ans = max(dp(id+1, remW), power[id]+dp(id+1, remW-W[id]));
}

int main(){

  int TC; scanf("%d", &TC);
  int K, R;
  while(TC--){
    memset(memo, -1, sizeof memo);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
      scanf("%d %d", &power[i], &W[i]);
    scanf("%d %d", &K, &R);

    int ans = dp(0, K);

    if(ans >= R) printf("Missao completada com sucesso\n");
    else         printf("Falha na missao\n");

  }

  return 0;
}
