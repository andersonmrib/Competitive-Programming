#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int m, n;
  int r;
  while(cin >> m >> n){

    vector<vector<pair<int, int>>> transpose (n, vector<pair<int, int>>());

    for(int i=0; i<m; i++){
      cin >> r;
      vector<int> indexes;

      for(int j=0; j<r; j++){
        int idx; cin >> idx; idx--;
        indexes.push_back(idx);
      }
      for(int j=0; j<r; j++){
        int value; cin >> value;
        transpose[indexes[j]].push_back({value, i+1});
      }
    }

    cout << n << " " << m << "\n";
    for(int i=0; i<n; i++){
      cout << transpose[i].size();
      for(auto x : transpose[i]) cout << " " << x.second;
      cout << "\n";

      bool first = true;
      for(auto x : transpose[i]){
        if(!first) cout << " ";
        cout << x.first;
        first = false;
      }
      cout << "\n";
    }
  }

  return 0;
}
