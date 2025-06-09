#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

unsigned long long ull;

int main(){

  speedBoost;
  int p, q, r, s;
  while(cin >> p >> q >> r >> s){

    q = min(q, p - q);
    s = min(s, r - s);

    int upperBound = max(q, s);
    double ans = 1.0;

    // Draw the formula on paper
    // Easily to see!
    for(int i=0; i<upperBound; i++){

      if(i < q)
        ans *= (p - i) / (i + 1.0);
      if(i < s)
        ans *= (i + 1.0) / (r - i);
    }

    printf("%.5lf\n", ans);
  }

  return 0;
}
