#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int l, n; cin >> l >> n;
    vector<int> pos(n);
    for(int i=0; i<n; i++)
      cin >> pos[i];

    int earliest = 0, latest = 0;
    for(auto x : pos){
      earliest = max(earliest, min(x, abs(l - x)));
      latest   = max(latest, max(x, abs(l - x)));
    }

    cout << earliest << " " << latest << endl;
  }

  return 0;
}
