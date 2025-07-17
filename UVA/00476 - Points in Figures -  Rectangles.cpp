#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef tuple<float, float, float, float> tup;
typedef vector<tup> tupff;

int main(){

  speedBoost;
  char r;
  float x1, y1, x2, y2;

  tupff vec;
  while(true){
    cin >> r;
    if(r == '*') break;
    cin >> x1 >> y1 >> x2 >> y2;
    vec.emplace_back(x1, y1, x2, y2);
  }

  float x, y;
  int point = 1;
  while(true){

    cin >> x >> y;
    if((int)(x * 10) == 99999 && (int)(y * 10) == 99999) break;

    bool contained = false;
    int figure = 1;
    for(auto [x1, y1, x2, y2] : vec){
      if(x < x2 && x > x1 && y > y2 && y < y1){
        contained = true;
        cout << "Point " << point << " is contained in figure " << figure << "\n";
      }
      figure++;
    }

    if(contained == false)
      cout << "Point " << point << " is not contained in any figure\n";
    point++;
  }

  return 0;
}
