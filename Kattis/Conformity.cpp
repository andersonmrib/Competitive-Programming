#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  unordered_map<string, int> umap;
  int mostPopular = 0;

  for(int i=0; i<n; i++){
    vector<int> vec(5, 0);
    for(int j=0; j<5; j++)
      cin >> vec[j];

    sort(vec.begin(), vec.end());

    string str = "";
    for(auto x : vec)
      str += to_string(x);
    umap[str]++;
    mostPopular = max(mostPopular, umap[str]);
  }

  int ans = 0;
  for(auto [s, num] : umap){
    if(num == mostPopular)
      ans += num;
  }

  cout << ans << "\n";

  return 0;
}
