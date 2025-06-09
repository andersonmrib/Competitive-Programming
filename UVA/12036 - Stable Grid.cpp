#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int grid[101][101];

int main(){

  speedBoost;

  int t; cin >> t;
  int NC = 0;
  while(t--){

    unordered_map<int, int> umap;

    int n; cin >> n;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> grid[i][j];
        umap[grid[i][j]]++;
      }
    }

    bool hasSolution = true;
    for(auto [f, s] : umap)
      if(s > n){
      hasSolution = false;
      break;
    }

    cout << "Case " << ++NC << ": ";
    if(hasSolution) cout << "yes\n";
    else            cout << "no\n";
  }

  return 0;
}
