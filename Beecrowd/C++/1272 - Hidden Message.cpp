#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string line, hiddenMessage;
    getline(cin, line);

    bool get = false;
    for(auto c : line){
      if(isalpha(c)){
        if(!get){
          hiddenMessage += c;
          get = true;
        }
      }
      else get = false;
    }
    cout << hiddenMessage << "\n";
  }

  return 0;
}
