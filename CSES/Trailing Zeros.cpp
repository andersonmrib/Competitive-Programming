#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int count5(int n, int p){
  int ans = 0;
  for(int pi=p; pi <= n; pi*=p)
    ans += n/pi;
  return ans;
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  cout << count5(n, 5) << endl;

  return 0;
}
