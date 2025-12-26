#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)as
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int32_t main(){

  speedBoost;
  int n; cin >> n;
  vi a(n);
  F(i, 0, n)
    cin >> a[i];

  int ans = INF;
  for(int mask=0; mask<(1<<n); mask++){
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i++){
      if((mask >> i) & 1) sum1 += a[i];
      else                sum2 += a[i];
    }
    ans = min(ans, abs(sum1 - sum2));
  }

  cout << ans << endl;

  return 0;
}

