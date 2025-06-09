#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  bool leftq = true;

  while(getline(cin, line)){
    for(auto c : line){
      if(c == '"'){
        if(leftq)
          cout << "``";
        else
          cout << "''";
        leftq = !leftq;
      }
      else cout << c;
    }
    cout << "\n";
  }

  return 0;
}
