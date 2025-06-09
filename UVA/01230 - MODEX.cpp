#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int mod(int a, int m) { return ((a % m) + m) % m ; }

int modPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if(p&1) ans = mod(ans*b, m);
  return ans;
}

int main(){

  speedBoost;
  int c; cin >> c;
  while(c--){
    int x, y, n; cin >> x >> y >> n;
    cout << modPow(x, y, n) << "\n";
  }

  return 0;
}
