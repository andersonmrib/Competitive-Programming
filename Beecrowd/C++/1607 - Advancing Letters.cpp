#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    string a, b; cin >> a >> b;
    int ans = 0;
    for(int i=0; i<a.size() && i<b.size(); i++){
      ans += (b[i] - a[i] + 26)%26;
    }
    cout << ans << "\n";
  }

  return 0;
}
