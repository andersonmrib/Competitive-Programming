#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int legendre(int n, int p){
  int ans = 0;
  for(int pi=p; pi<=n; pi*=p)
    ans += n/pi;
  return ans;
}

int main(){

  speedBoost;

  int N; cin >> N;
  int ans = legendre(N, 5);
  cout << ans << "\n";

  return 0;
}
