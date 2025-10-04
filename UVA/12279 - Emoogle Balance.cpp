#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  int NC = 1;
  while(cin >> n, n){

    int ans = 0;
    for(int i=0; i<n; i++){
      int x; cin >> x;
      if(x > 0) ans++;
      else      ans--;
    }

    cout << "Case " << NC++ << ": ";
    cout << ans << "\n";
  }

  return 0;
}
