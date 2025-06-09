#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int n; cin >> n;

  ll sum = 0, ans = -1e9;
  ll x;
  for(int i=0; i<n; i++){
    cin >> x;
    if(sum < 0) sum = 0;
    sum += x;
    ans = max(ans, sum);
  }

  cout << ans << "\n";

  return 0;
}
