#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int total = 0;
  while(t--){

    float len, wid, dep, wei;
    cin >> len >> wid >> dep >> wei;

    bool c1 = (len <= 56.0 && wid <= 45.0 && dep <= 25.0);
    bool c2 = (len + wid + dep <= 125.0);
    bool c3 = (wei <= 7.0);

    if((c1 || c2) && c3){
      cout << 1 << "\n";
      total++;
    }
    else
      cout << 0 << "\n";
  }

  cout << total << "\n";

  return 0;
}
