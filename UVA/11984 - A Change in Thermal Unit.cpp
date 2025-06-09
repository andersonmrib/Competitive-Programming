#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    int C, d; cin >> C >> d;

    double F = (double)9/5*C + 32;
    F += d;
    double newC = (F - 32)*5/9;
    printf("Case %d: %.2lf\n", ++numCases, newC);
  }

  return 0;
}
