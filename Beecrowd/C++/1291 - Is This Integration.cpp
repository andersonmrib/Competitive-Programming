#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  double a;
  while(cin >> a){

    double sqArea = a*a;
    double circle_1_4_Area = (M_PI*a*a)/4.0;
    double regionADC = sqArea - circle_1_4_Area;

    double chordSize = 2*a*sin(M_PI/12.0);
    double insideSqArea = chordSize*chordSize;
    double triArea = (a*a*sin(M_PI/6.0))/2.0;
    double circle_1_9_segment = M_PI*a*a/12.0;
    double striped = (circle_1_9_segment - triArea)*4 + insideSqArea;

    double dotted = (sqArea - regionADC*2 - striped)*2;
    double rest = sqArea - striped - dotted;

    printf("%.3lf %.3lf %.3lf\n", striped, dotted, rest);
  }

  return 0;
}
