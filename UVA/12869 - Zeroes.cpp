#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

int main(){

  speedBoost;
  ull low, high;
  while((cin >> low >> high), (low || high)){

    ull ans = high/5 - low/5 + 1;
    cout << ans << "\n";
  }

  return 0;
}
