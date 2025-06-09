#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main(){

  speedBoost;

  vi coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
  vector<ll> dp(30001, 0);
  dp[0] = 1;

  for(int i=0; i<coins.size(); i++){
    for(int j=coins[i]; j<30001; j++)
      dp[j] = (dp[j] + dp[j - coins[i]]);
  }

  float value;
  while(cin >> value){

    if(value == 0.0) break;

    cout << setw(6) << right << fixed << setprecision(2) << value;
    cout << setw(17) << right << dp[(int)round(value*100)] << "\n";
  }

  return 0;
}
