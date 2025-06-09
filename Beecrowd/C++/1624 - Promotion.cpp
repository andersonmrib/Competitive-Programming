#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_W = 110;

int N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == N) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), V[id]+dp(id+1, remW-W[id]));
}

int main(){

  while(scanf("%d", &N), N){

    memset(memo, -1, sizeof memo);
    for(int i=0; i<N; i++)
      scanf("%d %d", &V[i], &W[i]);

    int M; scanf("%d", &M);

    int ans = dp(0, M);

    printf("%d\n", ans);
  }

  return 0;
}
