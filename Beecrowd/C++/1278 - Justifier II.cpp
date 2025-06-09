#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
  speedBoost;
  int n;
  bool first = true;
  while((cin >> n), n){

    cin.ignore();
    vector<string> ans;

    if(!first) cout << "\n";
    first = false;

    for(int i=0; i<n; i++){
      string word, str, newString;
      getline(cin, str);

      stringstream ss(str);

      while(ss >> word){
        if(!newString.empty()) newString += " ";
        newString += word;
      }
      ans.push_back(newString);
    }

    int len = 0;
    for(auto w : ans) len = max(len, (int)w.size());
    for(auto w : ans) cout << setw(len) << right << w << "\n";
  }

  return 0;
}

