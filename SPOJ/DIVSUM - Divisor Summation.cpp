#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

void solve(){

  int MAX = 5e6+9;
  vi dp(MAX, 0);
  for(int i=1; i<MAX; i++)
    for(int j=i; j<MAX; j+=i)
      dp[j] += i;

  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    cout << dp[n] - n << endl;
  }
}

int32_t main(){

  speedBoost;
    solve();

  return 0;
}
