#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int position, c1, c2, c3;
  while((cin >> position >> c1 >> c2 >> c3)){
    if(!position && !c1 && !c2 && !c3) break;

    int ans = 1080;
    ans += 9 * ((position - c1 + 40) % 40);
    ans += 9 * ((c2 - c1 + 40) % 40);
    ans += 9 * ((c2 - c3 + 40) % 40);

    cout << ans << "\n";
  }

  return 0;
}
