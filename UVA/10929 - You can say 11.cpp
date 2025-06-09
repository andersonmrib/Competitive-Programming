#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string number;
  while(cin >> number){

    if(number == "0") break;

    int ans = 0;
    for(auto x : number)
      ans = (ans * 10 + x - '0') % 11;

    if(!ans) cout << number << " is a multiple of 11.\n";
    else     cout << number << " is not a multiple of 11.\n";
  }

  return 0;
}
