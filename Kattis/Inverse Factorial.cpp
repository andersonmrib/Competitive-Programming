#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
#define MOD 100000007

int main(){

  speedBoost;
  string str; cin >> str;

  int remaining = 0;
  for(auto c : str)
    remaining = (remaining * 10 + c - '0')%MOD;

  ll ans = 1;
  for(ll i=1; i<=remaining; i++){
    ans = ans * i;
    ans = ans%MOD;
    if(ans == remaining){
      cout << i << "\n";
      break;
    }
  }

  return 0;
}
