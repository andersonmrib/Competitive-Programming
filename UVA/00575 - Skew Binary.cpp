#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string skew;
  while(cin >> skew){
    if(skew == "0") break;

    int ans = 0;

    reverse(skew.begin(), skew.end());
    for(int i=0; i<skew.size(); i++){
      int power = (int)pow(2, i+1);
      ans += (skew[i] - '0') * (power - 1);
    }

    cout << ans << "\n";
  }

  return 0;
}
