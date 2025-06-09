#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  while(cin >> n){

    if(!n) break;

    int fullBottle = 0, emptyBotte = 0, ans = 0;
    while(n){
      ans += n/3;
      fullBottle = n/3;
      emptyBotte = n%3;
      emptyBotte += fullBottle;
      n = emptyBotte;
      if(!fullBottle) break;
    }

    // can I buy one more from the store?

    if(emptyBotte == 2) cout << ans+1 << "\n";
    else                cout << ans << "\n";
  }

  return 0;
}
