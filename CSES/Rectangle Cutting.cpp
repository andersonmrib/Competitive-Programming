#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;


int main(){

  speedBoost;
  int a, b; cin >> a >> b;

  vector<vi> dp(a+1, vi(b+1));
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      if(i == j){
        dp[i][j] = 0;
        continue;
      }

      int res = 1e9;
      for(int k=1; k<i; k++)
        res = min(res, 1 + dp[k][j] + dp[i-k][j]);
      for(int k=1; k<j; k++)
        res = min(res, 1 + dp[i][k] + dp[i][j-k]);
      dp[i][j] = res;
    }
  }

  cout << dp[a][b] << endl;

  return 0;
}
