#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    double a0, an1; cin >> a0 >> an1;

    double sum = 0;
    for(int i=0; i<n; i++){
      double ci; cin >> ci;
      sum += 2*(n - i) * ci;
    }

    double a1 = (an1 + n * a0 - sum) / (n + 1);
    cout << fixed << setprecision(2) << a1 << "\n";

    if(t) cout << "\n";
  }

  return 0;
}
