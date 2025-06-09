#include <bits/stdc++.h>
using namespace std;

int main(){

  double a, b, c;
  while(cin >> a >> b >> c){

    double ans = tan(a*M_PI/180.0)*b + c;
    cout << fixed << setprecision(2) << ans * 5 << endl;
  }

  return 0;
}
