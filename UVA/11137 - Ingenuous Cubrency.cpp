#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int32_t main(){

  speedBoost;
  int v;

  vector<int> coins;
  for(int i=1; i<=21; i++)
    coins.push_back(i*i*i);

  while(cin >> v){

    vector<int> dp(v+1);
    dp[0] = 1;

    for(auto c : coins){
      for(int j=c; j<=v; j++){
        dp[j] = (dp[j] + dp[j-c]);
      }
    }

    cout << dp[v] << endl;
  }

  return 0;
}
