#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int memo[10001];

int dp(int n){
  if(n < 0) return INT_MAX;
  if(n == 0) return 0;

  int &ans = memo[n];
  if(ans != -1) return ans;

  ans = INT_MAX;
  for(int i=1; i*i<=n; i++)
    ans = min(ans, 1 + dp(n - i*i));
  return ans;
}

int32_t main(){

  speedBoost;
  int t; cin >> t;
  memset(memo, -1, sizeof memo);
  while(t--){
    int n; cin >> n;
    cout << dp(n) << "\n";
  }

    return 0;
}