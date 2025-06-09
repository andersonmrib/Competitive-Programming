#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string number; cin >> number;

    int ans = 0, curr = 0;
    // *** builds the number from left to right ***
    for(auto x : number){
      curr = curr * 10 + (x - '0');
      int numOfOnes = __builtin_popcount(curr);
      ans = max(ans, numOfOnes);
    }
    cout << ans << "\n";
  }

  return 0;
}
