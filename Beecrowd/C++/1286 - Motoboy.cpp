#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 30;
const int MAX_W = 40;

int N, T[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == N) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), T[id]+dp(id+1, remW-W[id]));
}

int main(){

  while(scanf("%d", &N), N){
    memset(memo, -1, sizeof memo);
    int P; scanf("%d", &P);

    for(int i=0; i<N; i++)
      scanf("%d %d", &T[i], &W[i]);

    int ans = dp(0, P);
    printf("%d min.\n", ans);
  }

    return 0;
}
