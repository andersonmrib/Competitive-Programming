#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){
    int l, w, h;
    cin >> l >> w >> h;

    cout << "Case " << ++NC << ": ";
    if(l > 20 || w > 20 || h > 20)
      cout << "bad\n";
    else
      cout << "good\n";
  }

  return 0;
}
