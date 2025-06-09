#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Same code used in UVA 11877
int main(){

  speedBoost;
  int n;

  while(cin >> n){
    int fullBottle = 0, emptyBottle = 0, ans = n;
    while(n){

      ans += n/3;
      fullBottle = n/3;
      emptyBottle = n%3;
      emptyBottle += fullBottle;
      n = emptyBottle;
      if(!fullBottle) break;
    }

    if(emptyBottle == 2) cout << ans + 1 << "\n";
    else                 cout << ans << "\n";
  }

  return 0;
}
