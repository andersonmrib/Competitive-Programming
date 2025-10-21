#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"
using namespace std;

const int max_n = 52;
int dp[max_n][max_n];
void process(){
  dp[0][0] = 1;
  for(int n=1; n<max_n; n++){
    dp[n][0] = dp[n][n] = 1;
    for(int k=1; k<n; k++)
      dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
  }
}

int32_t main(){

  speedBoost;
  process();
  int t; cin >> t;
  while(t--){
    int r, c; cin >> r >> c;
    cout << dp[r+c-2][r-1] << endl;
  }

  return 0;
}
