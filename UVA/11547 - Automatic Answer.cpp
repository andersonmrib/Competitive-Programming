#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    int ans = ((((n*567)/9 + 7492)*235)/47) - 498;
    cout << (abs(ans/10)%10) << "\n";
  }

  return 0;
}
