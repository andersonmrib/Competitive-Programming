#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int x1, y1, x2, y2;
  while((cin >> x1 >> y1 >> x2 >> y2), (x1 || y1 || x2 || y2)){
    if(x1 == x2 && y1 == y2)
      cout << 0 << "\n";
    else if(x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1))
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }

  return 0;
}
