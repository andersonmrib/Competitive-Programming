#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  while(getline(cin, line)){

    list<char> lt;
    auto it = lt.begin();
    for(auto c : line){

      if(c == '['){
        it = lt.begin();
        continue;
      }

      else if(c == ']'){
        it = lt.end();
        continue;
      }

      lt.insert(it, c);
    }

    for(auto c : lt)
      cout << c;
    cout << "\n";
  }

  return 0;
}
