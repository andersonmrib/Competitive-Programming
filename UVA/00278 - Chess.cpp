#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    char c; cin >> c;
    int m, n; cin >> m >> n;

    if(c == 'r') cout << min(m, n) << "\n";
    else if(c == 'k') cout << ((n*m)%2 ? n*m/2+1 : n*m/2) << "\n";
    else if(c == 'Q') cout << min(m, n) << "\n"; // Queen's problem always have solution n >= 4
    else cout << ((n+1)/2) * ((m+1)/2) << "\n";
  }

  return 0;
}
