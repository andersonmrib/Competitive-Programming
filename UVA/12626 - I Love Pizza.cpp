#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int INF = 1e9;

int main(){

  speedBoost;
  int t; cin >> t;

  while(t--){

    string ingredients; cin >> ingredients;
    unordered_map<char, int> umap;
    umap['M'] = 0;
    umap['A'] = 0;
    umap['R'] = 0;
    umap['G'] = 0;
    umap['I'] = 0;
    umap['T'] = 0;

    for(auto c : ingredients) umap[c]++;

    vector<int> avaiable;
    avaiable.push_back(umap['M']);
    avaiable.push_back(umap['A']/3);
    avaiable.push_back(umap['R']/2);
    avaiable.push_back(umap['G']);
    avaiable.push_back(umap['I']);
    avaiable.push_back(umap['T']);

    int ans = INF;
    for(auto x : avaiable)
      ans = min(ans, x);
    cout << ans << "\n";
  }

  return 0;
}
