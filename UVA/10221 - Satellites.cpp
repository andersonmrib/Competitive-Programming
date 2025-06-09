#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  double s, a;
  string str;
  while(cin >> s >> a >> str){

    double radius = s + 6440.0;
    double perimeter = 2 * M_PI * radius;
    double angle;
    (str == "deg") ? (angle = a) : (angle = a/60.0);

    if(angle > 180.0) angle = 360.0 - angle;
    double radian = angle * M_PI / 180.0;

    double arc = angle/360.0*perimeter;
    double chord = 2.0 * radius * sin(radian/2.0);

    printf("%.6lf %.6lf\n", arc, chord);
  }

  return 0;
}
