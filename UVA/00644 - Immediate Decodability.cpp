#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string code;
  int NC = 0;
  while(cin >> code){
    vector<string> vec;
    vec.push_back(code);
    while(cin >> code){
      if(code == "9") break;
      else vec.push_back(code);
    }

    bool hasSolution = true;
    for(int i=0; i<vec.size() - 1; i++){
      if(!hasSolution) break;
      for(int j=i+1; j<vec.size(); j++){
        string a = vec[i], b = vec[j];
        if(a.find(b, 0) == 0 || b.find(a, 0) == 0) {
          hasSolution = false;
          break;
        }
      }
    }

    cout << "Set " << ++NC << " is ";
    if(hasSolution) cout << "immediately decodable\n";
    else            cout << "not immediately decodable\n";
  }

  return 0;
}
