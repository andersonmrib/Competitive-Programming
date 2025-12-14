#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int add(int b, int m) { return ((b+m)%m)%m; }

const int m = 1e9+7;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = add(ans*ans, m);
  if((p&1)) ans = add(ans*b, m);
  return ans;
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  cout << fastPow(2, n, m) << endl;

  return 0;
}
