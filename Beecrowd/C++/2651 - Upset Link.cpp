#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string str; cin >> str;
  transform(str.begin(), str.end(), str.begin(), ::tolower);

  bool hasSolution = false;
  for(int i=0; i<str.size(); i++){
    if(str[i] == 'z')
      if(str.substr(i, 5) == "zelda"){
        cout << "Link Bolado\n";
        hasSolution = true;
        break;
    }
  }

  if(!hasSolution)
    cout << "Link Tranquilo\n";

  return 0;
}
