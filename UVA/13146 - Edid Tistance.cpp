#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int dp[105][105];

int32_t main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy);
  while(t--){

    string a, b;
    getline(cin, a);
    getline(cin, b);

    int n = a.size(), m = b.size();
    for(int i=0; i<=n; i++)
      dp[i][0] = i;
    for(int j=0; j<=m; j++)
      dp[0][j] = j;

    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(a[i-1] == b[j-1])
          dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
      }
    }

    cout << dp[n][m] << endl;
  }

  return 0;
}
