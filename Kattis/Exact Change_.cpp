#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;
int MAX_VAL = 30005;

int main(){

  speedBoost
  int t; cin >> t;
  while(t--){

    int p, n; cin >> p >> n;
    vi coins(n);
    for(int i=0; i<n; i++)
      cin >> coins[i];

    vi dp(MAX_VAL, INF);
    dp[0] = 0;
    for(auto c : coins)
      for(int j=MAX_VAL-1; j>=c; j--)
        dp[j] = min(dp[j], dp[j-c] + 1);


    for(int v=p; v<MAX_VAL; v++){
      if(dp[v] != INF){
        cout << v << " " << dp[v] << endl;
        break;
      }
    }
  }

  return 0;
}
