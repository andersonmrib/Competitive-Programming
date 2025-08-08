#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
const ll mod = 1000;

int main(){

  speedBoost;
  ll n; cin >> n;

  ll ans = 1;
  int two = 0, five = 0;
  for(int i=n; i>1; i--){
    int j = i;
    while(j % 2 == 0) j /= 2, two++;
    while(j % 5 == 0) j /= 5, five++;
    ans = (ans * j) % mod;
  }

  two -= five;
  while(two--)
    ans = (ans * 2) % mod;

  if(n <= 6) cout << ans << "\n";
  else{
    string tmp = to_string(ans);
    while(tmp.size() < 3) tmp = '0' + tmp;
    cout << tmp << "\n";
  }

  return 0;
}
