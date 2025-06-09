#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;

  int fac[21];
  fac[0] = 1;
  for(int i=1; i<21; i++)
    fac[i] = fac[i-1] * i;

  int t; cin >> t;
  int NC = 0;
  while(t--){

    string word; cin >> word;

    int len = word.size();
    unordered_map<char, int> umap;
    for(auto c : word) umap[c]++;

    int ans = fac[len];
    for(auto [f, s] : umap)
      ans /= fac[s];
    cout << "Data set " << ++NC << ": ";
    cout << ans << "\n";
  }

  return 0;
}
