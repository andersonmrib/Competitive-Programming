#include <bits/stdc++.h>
using namespace std;

int main() {
  // 1D array solution (faster)
  int C, F, counter = 0;
  while(scanf("%d %d", &C, &F), (C || F)){
    vector<int> V(F), W(F);
    vector<int> dp(C + 1, 0);

    for(int i = 0; i < F; i++)
      scanf("%d %d", &W[i], &V[i]);

    for(int i = 0; i < F; i++){
      for(int w = C; w >= W[i]; w--){
        dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
      }
    }

    printf("Teste %d\n", ++counter);
    printf("%d\n\n", dp[C]);
  }

  return 0;
}

/*

// 2D array solution (a little bit slower)

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 60;
const int MAX_W = 1010;

int F, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == F) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), V[id]+dp(id+1, remW-W[id]));
}

int main(){

  int C, counter = 0;
  while(scanf("%d %d", &C, &F), (C || F)){
    memset(memo, -1, sizeof memo);
    for(int i=0; i<F; i++)
      scanf("%d %d", &W[i], &V[i]);

    printf("Teste %d\n", ++counter);

    int ans = dp(0, C);
    printf("%d\n\n", ans);
  }

  return 0;
}

*/
