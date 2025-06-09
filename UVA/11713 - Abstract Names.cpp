#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool isVowel(char c){
  return (c == 'a' || c == 'e' || c == 'i' ||
          c == 'o' || c == 'u');
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    string name, nickname;
    cin >> name >> nickname;

    if(name.size() != nickname.size()){
      cout << "No\n";
      continue;
    }

    bool hasSolution = true;
    for(int i=0; i<name.size(); i++){
      if((!isVowel(name[i]) || !isVowel(nickname[i])) && name[i] != nickname[i]){
        hasSolution = false;
        break;
      }
    }

    if(hasSolution) cout << "Yes\n";
    else            cout << "No\n";
  }

  return 0;
}
