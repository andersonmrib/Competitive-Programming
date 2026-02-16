#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int32_t main(){

  speedBoost;
  int n; cin >> n;

  bitset<100001> dp;
  dp[0] = 1;

  int mx = 0;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    dp |= (dp << x);
    mx += x;
  }

  vi results;
  for(int i=1; i<=mx; i++)
    if(dp[i])
      results.push_back(i);

  cout << results.size() << endl;
  for(int i=0; i<(int)results.size(); i++)
    cout << results[i] << (i == (int)results.size() - 1 ? "" : " ");
  cout << endl;

  return 0;
}
