#include <bits/stdc++.h>
#define int long long
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int32_t main(){

  speedBoost;
  int n;

  while((cin >> n), n){
    vector<int> nums(n);
    unordered_map<int, vector<pair<int, int>>> umap;
    for(int i=0; i<n; i++)
      cin >> nums[i];

    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
        umap[nums[i] + nums[j]].emplace_back(i, j);

    bool found = false;
    for(int d=n-1; d>=0 && !found; d--){
      for(int c=0; c<n && !found; c++){
        if(c == d) continue;
        int target = nums[d] - nums[c];
        if(umap.count(target)){
          for(auto [i, j] : umap[target]){
            if(i != d && j != d && i != c && j != c){
              cout << nums[d] << "\n";
              found = true;
            }
          }
        }
      }
    }

    if(!found) cout << "no solution\n";
  }

  return 0;
}


