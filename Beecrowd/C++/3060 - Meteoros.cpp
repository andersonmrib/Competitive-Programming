#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  speedBoost;
  int x1, y1, x2, y2;

  int numCases = 0;
  while((cin >> x1 >> y1 >> x2 >> y2), (x1 || y1 || x2 || y2)){

    int n; cin >> n;
    int ans = 0;

    while(n--){
      int x, y; cin >> x >> y;
      if(x <= x2 && x >= x1 && y <= y1 && y >= y2) ans++;
    }

    cout << "Teste " << ++numCases << endl;
    cout << ans << endl;
  }

  return 0;
}
