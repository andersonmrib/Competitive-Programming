#include <bits/stdc++.h>
using namespace std;

int main(){

  int D, VF, VG;
  while(cin >> D >> VF >> VG){

    float hypotenuse = sqrt(144 + D*D);
    float boatTime = 12/(float)VF;
    float guardTime = hypotenuse/(float)VG;

    if(boatTime < guardTime) cout << "N\n";
    else                     cout << "S\n";
  }

  return 0;
}
