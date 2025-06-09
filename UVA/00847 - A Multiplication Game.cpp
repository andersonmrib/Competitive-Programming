#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  ll n;

  while(cin >> n){

    int Ollie = 1, Stan = 0;
    ll p = 1;

    while(p < n){
      if(Ollie){
        p *= 9;
        swap(Ollie, Stan);
      }
      else if(Stan){
        p *= 2;
        swap(Ollie, Stan);
      }
    }

    if(Ollie) cout << "Ollie wins.\n";
    else      cout << "Stan wins.\n";
  }

  return 0;
}
