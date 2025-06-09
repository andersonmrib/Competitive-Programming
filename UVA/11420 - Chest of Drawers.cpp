#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

ull memo[70][70][2];

ull dp(int n, int s, bool prev){ // 1 for locked, 0 for unlocked
  if(n == 0 && s == 0) return memo[n][s][prev] = 1;
  if(n < 0 || s < 0 || n < s) return 0;

  ull &ans = memo[n][s][prev];
  if(ans != -1) return ans;

  if(prev) ans = dp(n-1, s-1, 1) + dp(n-1, s, 0);
  else     ans = dp(n-1, s, 1)   + dp(n-1, s, 0);
  return ans;
}

int main(){

  speedBoost;
  int n, s;
  memset(memo, -1, sizeof memo);
  while(cin >> n >> s){
    if(n < 0 && s < 0) break;
    cout << dp(n, s, 1) << "\n";
  }

  return 0;
}


