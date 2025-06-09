#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  double l, w, h, theta;
  while(cin >> l >> w >> h >> theta){

    double height = tan(theta*M_PI/180) * l;
    double fullVolume = l * w * h;

    double remainingVolume;
    if(height <= h){
      double spilledMilk = (l * height / 2) * w;
      remainingVolume = fullVolume - spilledMilk;
    }
    else{
      double base = h / tan(theta*M_PI/180);
      double filledVolume = (base * h / 2) * w;
      remainingVolume = filledVolume;
    }

    cout << fixed << setprecision(3) << remainingVolume << " mL\n";
  }

  return 0;
}
