#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  double f;
  while(cin >> f){
    double ans = sin(108*M_PI/180)/sin(63*M_PI/180)*f;
    cout << fixed << setprecision(10) << ans << "\n";
  }
  return 0;
}
