#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 30;
const int MAX_M = 210;
int M, C, price[MAX_gm][MAX_gm];
int memo[MAX_gm][MAX_M];

int dp(int g, int money){
  if(money < 0) return -1e9;   // invalid choice
  if(g == C) return M-money;   // done
  if(memo[g][money] != -1) return memo[g][money];
  int ans = -1;
  for(int k=1; k <= price[g][0]; k++)
    ans = max(ans, dp(g+1, money-price[g][k]));
  return memo[g][money] = ans;
}

int main(){

  int n; scanf("%d", &n);
  while(n--){
    scanf("%d %d", &M, &C);
    for(int g=0; g<C; g++){
      scanf("%d", &price[g][0]);

      for(int k=1; k <= price[g][0]; k++)
        scanf("%d", &price[g][k]);
    }
    memset(memo, -1, sizeof memo);

    if(dp(0, M) < 0) printf("no solution\n");
    else             printf("%d\n", dp(0, M));
  }

  return 0;
}
