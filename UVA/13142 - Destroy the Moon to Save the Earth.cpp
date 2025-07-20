#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    double T, S, D; cin >> T >> S >> D;
    // T(time impact), S(speed of the moon), D(distance for impact).

    double timeSec = T * 24 * 3600;
    double dmm = D * 1000000;
    double speed = dmm / timeSec;

    if(floor(speed) > 0)
      cout << "Remove " << (int)floor(speed) << " tons\n";
    else
      cout << "Add " << (int)floor(abs(speed)) << " tons\n";
  }

  return 0;
}
