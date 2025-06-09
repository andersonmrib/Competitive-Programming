#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int L; cin >> L;

    double W = 60*L/100.0;
    double radius = 20*L/100.0;
    double red = M_PI*radius*radius;
    double green = W*L - red;

    printf("%.2lf %.2lf\n", red, green);
  }

  return 0;
}
