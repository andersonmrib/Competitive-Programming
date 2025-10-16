#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    int mtr[n][m];

    memset(mtr, 0, sizeof mtr);
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> mtr[i][j];
      }
    }

    bool hasSolution = true;
    for(int j=0; j<m; j++){
      int sum = 0;
      for(int i=0; i<n; i++){
        sum += mtr[i][j];
      }
      if(sum != 2){
        hasSolution = false;
        break;
      }
    }

    if(hasSolution){
      set<pair<int, int>> edges;
      for(int j=0; j<m; j++){
        vector<int> pp;
        for(int i=0; i<n; i++){
          if(mtr[i][j])
            pp.push_back(i);
        }
        int u = min(pp[0], pp[1]);
        int v = max(pp[0], pp[1]);
        edges.insert({u, v});
      }

      if(edges.size() != m)
        hasSolution = false;
    }

    if(hasSolution)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
