#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int ans = INT_MIN;
    int n; cin >> n;
    for(int i=0; i<n; i++){
      int speed; cin >> speed;
      ans = max(ans, speed);
    }
    cout << "Case " << ++NC << ": " << ans << "\n";
  }

  return 0;
}
