#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int r; cin >> r;
    vector<int> vec(r, 0);
    for(int i=0; i<r; i++)
      cin >> vec[i];

    sort(vec.begin(), vec.end());
    int median = vec[r/2];

    int ans = 0;
    for(auto v : vec)
      ans += abs(v - median);
    cout << ans << "\n";
  }

  return 0;
}
