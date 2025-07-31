#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  bool first = true;
  while(true){

    getline(cin, line);
    if(line.empty()) break;

    string str = "";

    for(auto c : line)
      if(c != ' ') str += c;

    for(int i=1; i<=str.size(); i++){
      unordered_map<string, int> umap;
      for(int j=0; j+i-1<str.size(); j++)
        umap[str.substr(j, i)]++;
      int ans = -1e9;
      for(auto [s, ctt] : umap)
        ans = max(ans, ctt);
      if(ans > 1) cout << ans << "\n";
      else break;
    }

    cout << "\n";
  }

  return 0;
}
