#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string line;
  unordered_map<string, string> umap;
  while(getline(cin, line)){
    if(line.empty()) break;

    stringstream ss(line);
    string a, b;
    ss >> a >> b;
    umap[b] = a;
  }

  while(cin >> line){
    if(umap.count(line))
      cout << umap[line] << "\n";
    else cout << "eh\n";
  }

  return 0;
}
