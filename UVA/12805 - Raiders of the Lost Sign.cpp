#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int num; cin >> num;

    vector<int> factors;
    for(int i=2; i*i<=num; i++){
      while(num%i == 0){
        factors.push_back(i);
        num /= i;
      }
    }

    if(num != 1) factors.push_back(num);

    int ans = 1;
    for(auto p : factors)
      if(p % 4 == 1) ans *= -1;

    if(ans == 1) cout << "+\n";
    else         cout << "-\n";
  }

  return 0;
}
