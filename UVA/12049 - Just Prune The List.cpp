#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    vector<int> vecN(n), vecM(m);

    for(int i=0; i<n; i++)
      cin >> vecN[i];

    unordered_multiset<int> usetN(vecN.begin(), vecN.end());

    int value;
    int ans = 0;
    for(int i=0; i<m; i++){
      cin >> value;
      auto it = usetN.find(value);
      if(it == usetN.end())
        ans++;
      else
        usetN.erase(it);
    }
    ans += usetN.size();
    cout << ans << "\n";
  }

  return 0;
}
