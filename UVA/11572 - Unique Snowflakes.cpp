#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++)
      cin >> a[i];

    unordered_map<int, int> umap;
    int l = 0, ans = 0;
    for(int r=0; r<n; r++){
      while(umap[a[r]]) umap[a[l++]] = 0;
      umap[a[r]] = 1;
      ans = max(ans, r - l + 1);
    }

    cout << ans << endl;
  }

  return 0;
}
