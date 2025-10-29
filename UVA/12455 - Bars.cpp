#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;  // target value.
    int p; cin >> p;
    vector<int> bars(p);
    for(int i=0; i<p; i++)
      cin >> bars[i];

    int total_masks = 1<<p;
    bool ok = false;

    for(int mask=0; mask<total_masks && !ok; mask++){
      int len = 0;
      for(int j=0; j<p; j++){
        if(mask & (1<<j)) len += bars[j];
        if(len == n) ok = true;
      }
    }

    if(ok == true) cout << "YES\n";
    else           cout << "NO\n";
  }

  return 0;
}
