#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int m, n;
  while((cin >> m >> n), (m || n)){

    int ans;
    if(m == 1 || n == 1) ans = n*m;
    else if(m == 2 || n == 2){
      int aux = max(n, m);
      ans = (aux/4) * 4 + min(2, aux%4) * 2;
    }
    else ans = (m*n)%2 ? (m*n)/2+1 : (m*n)/2;
    cout << ans;
    cout << " knights may be placed on a " << m << " row " << n << " column board.\n";
  }

  return 0;
}

