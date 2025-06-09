#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n, p, q;
    cin >> n >> p >> q;

    vector<int> w(n);
    for(int i=0; i<n; i++)
      cin >> w[i];

    int ans = 0;
    for(auto eggW : w){
      p--, q -= eggW;
      if(p >= 0 && q >= 0) ans++;
    }

    cout << "Case " << ++NC << ": " << ans << "\n";
  }

  return 0;
}
