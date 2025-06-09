#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int k;
  while (cin >> k){
    int n, m; cin >> n >> m;

    while (k--){
      int x, y; cin >> x >> y;
      x -= n, y -= m;

      if (y > 0) {
        if      (x > 0) printf("NE\n");
        else if (x < 0) printf("NO\n");
        else            printf("divisa\n");
      } else if (y < 0) {
        if      (x > 0) printf("SE\n");
        else if (x < 0) printf("SO\n");
        else            printf("divisa\n");
      } else            printf("divisa\n");
    }
  }

  return 0;
}
