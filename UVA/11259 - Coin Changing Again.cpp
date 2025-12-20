#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

const int INF = 1e9;
const int MAX_V = 100005;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int coins[4], rem[4];
int dp[MAX_V];

int32_t main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    for(int i=0; i<4; i++)
      cin >> coins[i];
    int q; cin >> q;

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(auto c : coins)
      for(int j=c; j<MAX_V; j++)
        dp[j] = (dp[j] + dp[j-c]);

    while(q--){

      for(int i=0; i<4; i++)
        cin >> rem[i];

    int v; cin >> v;

    ll ans = 0;
    for(int mask=0; mask<16; mask++){

      ll curV = v;
      int bitsOn = 0;
      for(int i=0; i<4; i++){
        if((mask >> i) & 1){
          bitsOn++;
          curV -= (rem[i] + 1) * coins[i];
        }
      }

      if(curV >= 0){
        if(bitsOn % 2 == 0)
          ans += dp[curV];
        else
          ans -= dp[curV];
      }
    }

      cout << ans << endl;
    }
  }

  return 0;
}
