#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  string gun;
  while(cin >> gun){

    int danger = 0, bullets = 0, zeros = 0;
    int n = gun.size();

    for(int i=0; i<n; i++){
      if(gun[i] == '0'){
        zeros++;
        int next = (i + 1) % n;
        if(gun[next] == '1') danger++;
      }
      else bullets++;
    }

    double p_to_die = (double)danger / zeros;
    double p_fall_into_trap = (double)bullets / n;

    if(fabs(p_to_die - p_fall_into_trap) < 1e-9)
      cout << "EQUAL\n";
    else if(p_to_die < p_fall_into_trap)
      cout << "SHOOT\n";
    else
      cout << "ROTATE\n";
  }

  return 0;
}


