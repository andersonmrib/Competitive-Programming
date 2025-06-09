#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  ll n; cin >> n;
  int meowFactor;

  for(int i=2; i<128; i++){
    ll power = 1;
    for(int j=0; j<9; j++)
      power *= i;

    if(n % power == 0)
      meowFactor = i;
  }
  cout << meowFactor << "\n";

  return 0;
}
