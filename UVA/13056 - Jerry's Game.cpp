#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    int r, v; cin >> r >> v;
    cout << "Case " << ++numCases << ": ";
    cout << setprecision(8) << fixed << (double) r*M_PI/(2*v) << "\n";
  }

  return 0;
}
