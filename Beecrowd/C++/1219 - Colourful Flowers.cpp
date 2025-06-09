#include <bits/stdc++.h>
using namespace std;

int main(){

  int a, b, c;
  while((cin >> a >> b >> c)){

    double p = (a + b + c)/2.0;
    double triangleArea = sqrt(p*(p-a)*(p-b)*(p-c));

    double circleRadius = (a*b*c)/(4.0*triangleArea);
    double circleArea = M_PI*circleRadius*circleRadius - triangleArea;

    double littleCircleRadius = triangleArea/p;
    double littleCircleArea = M_PI*littleCircleRadius*littleCircleRadius;

    double triangleRealArea = triangleArea - littleCircleArea;

    printf("%.4lf %.4lf %.4lf\n", circleArea, triangleRealArea, littleCircleArea);
  }

  return 0;
}
