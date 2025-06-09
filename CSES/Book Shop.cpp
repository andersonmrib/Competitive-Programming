#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAX_X = 1e5 + 1;
int dp[MAX_X];

int main(){

  speedBoost;
  int n, x;
  cin >> n >> x;

  vector<int> weight(n), value(n);
  for(int &p : weight) cin >> p;
  for(int &s : value) cin >> s;

  for(int i=0; i<n; i++){
    for(int w=x; w>=weight[i]; w--)
      dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
  }

  cout << dp[x] << "\n";

  return 0;
}
