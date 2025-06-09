#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define INF 1e9
using namespace std;

vector<int> coins;
typedef long long ll;

int dp(int x){

  vector<ll> dp(x + 1, INF);
  dp[0] = 0;

  for(int i=1; i<=x; i++){
    for(int j=0; j<coins.size(); j++){
      if(coins[j] > i || dp[i - coins[j]] == INF)
        continue;
      dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
  }
  if(dp[x] != INF)
    return dp[x];
  return -1;
}

int main(){

  speedBoost;
  int n, x;
  cin >> n >> x;

  coins.assign(n, 0);
  for(int i=0; i<n; i++)
    cin >> coins[i];

  cout << dp(x) << "\n";

  return 0;
}
