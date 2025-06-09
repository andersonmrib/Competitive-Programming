#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000007
using namespace std;

typedef long long ll;

vector<int> coins;

ll solve(int x){

  vector<ll> dp(x+1, 0);
  dp[0] = 1;

  for(int i=0; i<coins.size(); i++){
    for(int j=coins[i]; j<=x; j++){
      dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
    }
  }
  return dp[x];

}

int main(){

  speedBoost;

  int n, x; cin >> n >> x;

  coins.assign(n, 0);
  for(int i=0; i<coins.size(); i++)
    cin >> coins[i];

  cout << solve(x) << "\n";

  return 0;
}


