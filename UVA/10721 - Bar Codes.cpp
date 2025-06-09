#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;
ull memo[51][51][51][2];

int global_m;
ull dp(int n, int k, int m, int color){

  if(n < 0 || k < 0 || m < 0) return 0;
  if(n == 0 && k == 0) return 1;
  if(n == 0 || k == 0) return 0;

  ull &ans = memo[n][k][m][color];
  if(ans != (ull)-1) return ans;

  ans = 0;
  if(color){ // Keep black, or change to white
    if(m > 1) ans += dp(n-1, k, m-1, 1);
    ans += dp(n-1, k-1, global_m, 0);
  }
  else{     // Keep white, or change to black
    if(m > 1) ans += dp(n-1, k, m-1, 0);
    ans += dp(n-1, k-1, global_m, 1);
  }
  return ans;
}

int main(){

  speedBoost;
  int n, k, m;
  while((cin >> n >> k >> m)){
    global_m = m;
    memset(memo, -1, sizeof memo);
    cout << dp(n, k, m, 1) << "\n";
  }
  return 0;
}
