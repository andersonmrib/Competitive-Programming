#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_T = 610;

int N, S[MAX_N], T[MAX_N], memo[MAX_N][MAX_T];

int dp(int ride, int remT){
  if((ride == N) || (remT == 0)) return 0;
  int &ans = memo[ride][remT];
  if(ans != -1) return ans;
  if(T[ride] > remT) return ans = dp(ride+1, remT);
  return ans = max(dp(ride+1, remT), S[ride]+dp(ride, remT-T[ride]));
  // we can repeat the ride! look at the second parameter inside the function "max"
}

int main(){

  int inst = 0, AT;
  while(scanf("%d %d", &N, &AT), N){
    memset(memo, -1, sizeof memo);
    for(int i=0; i<N; i++)
      scanf("%d %d", &T[i], &S[i]);

   int ans = dp(0, AT);

   printf("Instancia %d\n", ++inst);
   printf("%d\n\n", ans);
  }

  return 0;
}
