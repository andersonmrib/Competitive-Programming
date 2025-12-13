#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  vector<int> dp(n+1, 1e9);
  dp[n] = 0;
  for(int x=n; x>=1; x--){
    for(auto c : to_string(x)){
      int digit = c - '0';
      if(digit > 0)
        dp[x-digit] = min(dp[x-digit], dp[x] + 1);
    }
  }

  cout << dp[0] << endl;

  return 0;
}
