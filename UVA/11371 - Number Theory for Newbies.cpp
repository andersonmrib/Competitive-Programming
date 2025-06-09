#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  string number;
  while(cin >> number){

    sort(number.begin(), number.end());
    if(number[0] == '0'){
      for(int i=1; i<number.size(); i++){
        if(number[i] != '0'){
          swap(number[0], number[i]);
          break;
        }
      }
    }

    ll b = stoll(number);
    sort(number.rbegin(), number.rend());
    ll a = stoll(number);

    ll diff = a-b;
    ll k = diff/9;

    cout << a << " - " << b << " = " << diff << " = 9 * " << k << "\n";
  }

  return 0;
}
