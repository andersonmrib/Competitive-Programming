#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int f; cin >> f;

    ll ans = 0;
    for(int i=0; i<f; i++){
      int s, n, ef; cin >> s >> n >> ef;
      ans += s*ef;
    }
    cout << ans << endl;
  }

  return 0;
}
