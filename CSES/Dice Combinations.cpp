#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000007
using namespace std;

typedef long long ll;

int main(){

  speedBoost;

  int n; cin >> n;

  vector<ll> dp(n+1, 0);
  dp[0] = 1;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=6 && j<=i; j++){
      dp[i] = (dp[i] + dp[i-j])%MOD;
    }
  }

  cout << dp[n] << "\n";

  return 0;
}


