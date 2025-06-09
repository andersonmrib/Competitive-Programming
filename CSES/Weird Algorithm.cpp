#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  ll n; cin >> n;
  while(true){

    if(n == 1) break;
    cout << n << " ";
    if((n&1) == 1) n = n*3 + 1;
    else           n /= 2;
  }
  cout << n << "\n";

  return 0;
}
