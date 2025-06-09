#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main(){

  speedBoost;

  vi coins = {1, 5, 10, 25, 50};

  vector<ll> dp(30001, 0);
  dp[0] = 1;

  for(int i=0; i<coins.size(); i++){
    for(int j=coins[i]; j<30001; j++){
      dp[j] = (dp[j] + dp[j - coins[i]]);
    }
  }

  int n;
  while(cin >> n){
    if(dp[n] > 1)
      cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
    else
      cout << "There is only " << dp[n] << " way to produce " << n << " cents change.\n";

  }

  return 0;
}
