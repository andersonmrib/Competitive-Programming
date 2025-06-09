#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define EPS 1e-9

int main(){

  speedBoost;
  double number, cutoff;
  while(cin >> number >> cutoff){

    int ans = number;
    double fracPart = number - (int)number;
    if(fracPart - cutoff > EPS) ans++;
    cout << ans << "\n";
  }

  return 0;
}
