#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string flawed, number;
  while(cin >> flawed >> number){
    if(flawed == "0" && number == "0") break;

    bool foundNonZero = false;
    for(int i=0; i<number.size(); i++){
      if(number[i] == flawed[0]) continue;
      if(number[i] != '0' || foundNonZero){
        cout << number[i];
        foundNonZero = true;
      }
    }

    if(!foundNonZero) cout << "0";
                      cout << "\n";
  }

  return 0;
}
