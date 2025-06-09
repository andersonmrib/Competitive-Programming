#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const double EPS = 1e-9;

int main(){

  speedBoost;
  double a, b, c;
  while(cin >> a >> b >> c){

    double s = (a + b + c)/2.0;
    double triArea = sqrt(s*(s - a) * (s - b) * (s - c));
    if(a == 0 || b == 0 || c == 0)
      printf("The radius of the round table is: %.3lf\n", EPS);
    else
      printf("The radius of the round table is: %.3lf\n", triArea/s);
  }

  return 0;
}
