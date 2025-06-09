#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main(){

  speedBoost;
  ll fib[10010] = {0};
  fib[1] = 2;
  fib[2] = 3;
  fib[3] = 5;

  for(int i=4; i<10010; i++)
    fib[i] = ((fib[i-1]%MOD) + (fib[i-2]%MOD))%MOD;

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    cout << fib[n] << "\n";
  }

  return 0;
}
