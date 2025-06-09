#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int h1, m1, h2, m2;
  while((cin >> h1 >> m1 >> h2 >> m2), (h1 || m1 || h2 || m2)){
    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;

    int diff = end - start;
    if(diff < 0) diff += 24 * 60;
    cout << diff << "\n";
  }

  return 0;
}
