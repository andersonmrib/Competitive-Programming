#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
  while(cin >> n){

    int ans = 0;
    for(int i=8; i>=1; i--){
      while(fac[i] <= n){
        n -= fac[i];
        ans++;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
