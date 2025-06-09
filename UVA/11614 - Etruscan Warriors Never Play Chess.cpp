#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  // Solve the quadratic equation

  int t; cin >> t;
  while(t--){

    ll n; cin >> n;
    cout << (ll)(-1 + sqrt(1 + 8.0*n))/2 << "\n";
  }

  return 0;
}
