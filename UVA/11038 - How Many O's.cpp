#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

int countZ(int n){

  int ans = 1; // Starts at 0
  int power = 1;

  while(power <= n){

    int prefix = n / (power * 10);
    int midNum = (n / power) % 10;
    int suffixx = n % power;

    ans += prefix * power;
    if(midNum == 0){
      ans -= power;
      ans += suffixx + 1;
    }

    power *= 10;
  }

  return ans;
}

int32_t main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    if(m < 0) return 0;

    int ans = countZ(m) - countZ(n-1);
    cout << ans << endl;
  }

  return 0;
}

