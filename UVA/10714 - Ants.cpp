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
      int dist = min(x, abs(x - l));
      earliest = max(earliest, dist);
      latest = max(latest, max(x, l - x));
    }

    cout << earliest << " " << latest << endl;
  }

  return 0;
}
