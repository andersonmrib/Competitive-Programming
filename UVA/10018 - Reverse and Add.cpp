#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int ans = 0;
    string original, reversed, tmp; cin >> original;

    while(true){

      tmp = original;
      reverse(tmp.begin(), tmp.end());
      reversed = tmp;

      if(original == reversed) break;

      ll a = stol(original), b = stol(reversed);
      ll sum = a + b;

      original = to_string(sum);
      ans++;
    }

    cout << ans << " " << original << "\n";
  }

  return 0;
}
