#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    ll n, m; cin >> n >> m;
    ll an = m - 1, a1 = an - n + 1;
    ll ans = (a1 + an)*n/2;
    cout << ans << "\n";
  }

  return 0;
}
