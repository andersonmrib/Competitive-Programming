#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n; cin >> n;

  vi a(n);
  int sum = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    sum += a[i];
  }

  vector<vi> dp(n, vi(n));
  for(int len=1; len<=n; len++){
    for(int i=0; i<=n-len; i++){
      int j = i + len - 1;
      if(i == j)
        dp[i][j] = a[i];
      else
        dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
    }
  }

  cout << (sum + dp[0][n-1]) / 2 << endl;

  return 0;
}
