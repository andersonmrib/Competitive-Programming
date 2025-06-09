#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  unordered_map<string, vector<string>> umap;
  set<string> ans;

  while(getline(cin, line)){

    if(line == "#") break;
    stringstream ss(line);
    string word;

    while(ss >> word){
      string copy = word;
      transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
      sort(copy.begin(), copy.end());
      umap[copy].push_back(word);
    }
  }

  for(auto [sortedString, words] : umap)
    if(words.size() == 1) ans.insert(words[0]);

  for(auto s : ans) cout << s << "\n";

  return 0;
}
