#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    int a, b; cin >> a >> b;
    int ans = 0;

    if((a&1) == 0) a++;
    if((b&1) == 0) b--;

    for(int i=a; i<=b; i+=2)
      ans += i;
    cout << "Case " << ++numCases << ": " << ans << "\n";
  }

  return 0;
}
