#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int k; cin >> k;
    unordered_map<int, int> umap;

    int f0 = 1, f1 = 1;
    int idx = 1;
    while(true){

      int f2 = (f0 + f1)%k;
      if(umap.count(f2)){
        cout << umap[f2] << "\n";
        break;
      }
      else{
        umap[f2] = ++idx;
        f0 = f1, f1 = f2;
      }
    }
  }

  return 0;
}
