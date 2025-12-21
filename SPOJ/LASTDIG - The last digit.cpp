#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1) == 1) ans = ans * b % m;
  return ans;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int a, b; cin >> a >> b;
    cout << fastPow(a, b, 10) << endl;
  }

  return 0;
}
