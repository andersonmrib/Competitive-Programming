#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  double x1, y1, x2, y2, x3, y3;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
    // Let's create a triangle with these 3 points
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Get the semi-perimeter
    double s = (a + b + c)/2.0;
    double triArea = sqrt(s*(s-a)*(s-b)*(s-c));

    // Circumscribed circle's formula
    double radius = (a*b*c)/(4*triArea);

    printf("%.2lf\n", 2*M_PI*radius);
  }

  return 0;
}
