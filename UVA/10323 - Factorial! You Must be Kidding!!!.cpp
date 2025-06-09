#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ull;

// Negative factorial concept: read it more about inside the link below
// https://algorithmist.com/wiki/UVa_10323_-_Factorial!_You_Must_be_Kidding!!!

int main(){

  speedBoost;

  ull fac[14]; fac[0] = fac[1] = 1;
  for(int i=2; i<14; i++)
    fac[i] = fac[i-1]*i;

  int n;
  while(cin >> n){

    if(n < 0){
      if(n%2 != 0) cout << "Overflow!\n";
      else         cout << "Underflow!\n";
    }
    else if(n > 13)
      cout << "Overflow!\n";
    else if(n < 14 && fac[n] < 10000)
      cout << "Underflow!\n";
    else
      cout << fac[n] << "\n";
  }

  return 0;
}
