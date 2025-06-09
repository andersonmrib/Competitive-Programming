#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int memo[86][50];
int dp(int level, int branch_prev){

  if(level == 0) return 1;
  if(level < 0) return 0;

  int &ans = memo[level][branch_prev];
  if(ans != -1) return ans;

  ans = 0;
  if(branch_prev) ans += dp(level-1, 1) + dp(level-1, 0);
  else            ans += dp(level-1, 1);
  return ans;
}

int32_t main(){

  speedBoost;
  memset(memo, -1, sizeof memo);
  int level;
  while((cin >> level), level){
    cout << dp(level-1, 0) << "\n";
  }

  return 0;
}
