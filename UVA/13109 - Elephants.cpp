#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int m, w; cin >> m >> w;

    vector<int> elephants(m);
    for(auto &x : elephants)
      cin >> x;

    sort(elephants.begin(), elephants.end());

    int sum = 0, ans = 0;
    for(auto wei : elephants){
      sum += wei;
      if(sum < w) ans++;
      else break;
    }

    cout << ans << "\n";
  }

  return 0;
}
