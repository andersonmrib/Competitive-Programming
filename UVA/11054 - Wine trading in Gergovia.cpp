#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int32_t main(){

  speedBoost;
  int n;
  while(cin >> n, n){

    vector<int> a(n);
    for(int i=0; i<n; i++)
      cin >> a[i];

    int demand = 0, ans = 0;
    for(auto x : a){
      demand += x;
      ans += abs(demand);
    }
    cout << ans << endl;
  }

  return 0;
}
