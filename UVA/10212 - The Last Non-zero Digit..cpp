#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
const int mod = 1e9;

int main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    ll ans = 1;
    for(int i=n; i>n-m; i--){
      ans *= i;
      while(ans % 10 == 0) ans /= 10;
      ans %= mod;
    }

    cout << ans % 10 << "\n";
  }

  return 0;
}
