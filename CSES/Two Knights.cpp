#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int solve(int k){

  int totalWays = k*k*(k*k-1)/2;
  int attackingWays = 4*(k-1)*(k-2);
  return totalWays - attackingWays;
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  for(int k=1; k<=n; k++)
    cout << solve(k) << endl;

  return 0;
}
