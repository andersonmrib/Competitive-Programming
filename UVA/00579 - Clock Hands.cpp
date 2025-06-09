#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  string line;
  while(cin >> line){

    if(line == "0:00") break;

    int h, m;
    sscanf(line.c_str(), "%d:%d", &h, &m);

    double hourAngle = (h % 12) * 30 + m * 0.5;
    double minuteAngle = m * 6;
    double ans = abs(hourAngle - minuteAngle);

    printf("%.3lf\n", min(ans, 360 - ans));
  }

  return 0;
}
