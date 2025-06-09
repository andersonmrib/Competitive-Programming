#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int step, mod;
  while(cin >> step >> mod){

    cout << setw(10) << right << step;
    cout << setw(10) << right << mod;
    cout << "    ";
    int ans = __gcd(step, mod);
    if(ans != 1) cout << "Bad Choice\n\n";
    else         cout << "Good Choice\n\n";
  }

  return 0;
}
