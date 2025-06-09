#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int m; cin >> m;
    vector<int> coins(m);

    int sum = 0;
    for(int i=0; i<m; i++){
      cin >> coins[i];
      sum += coins[i];
    }

    int half = sum/2;
    vector<bool> dp(half+1, false);
    dp[0] = true;

    for(int i=0; i<m; i++)
      for(int j=half; j>=coins[i]; j--)
        dp[j] = dp[j] || dp[j - coins[i]];

    for(int i=half; i>=0; i--){
      if(dp[i]){
        cout << sum - 2*i << "\n";
        break;
      }
    }
  }

  return 0;
}


