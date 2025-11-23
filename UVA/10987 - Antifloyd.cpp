#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int INF = 1e9;

using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 1;
  while(t--){

    int n; cin >> n;
    vector<vector<int>> AL(n, vector<int>(n));
    for(int i=0; i<n-1; i++){
      for(int j=0; j<=i; j++){
        int w; cin >> w;
        AL[i+1][j] = w;
        AL[j][i+1] = w;
      }
    }

    bool stop = false;
    for(int k=0; k<n && !stop; k++){
      for(int i=0; i<n && !stop; i++){
        for(int j=0; j<n && !stop; j++){
          if(AL[i][j] == INF) continue;
          if(AL[i][k] + AL[k][j] == AL[i][j] && i != k && j != k)
            AL[i][j] = INF;

          else if(AL[i][k] + AL[k][j] < AL[i][j])
            stop = true;
        }
      }
    }

    cout << "Case #" << NC++ << ":\n";
    if(stop){
      cout << "Need better measurements.\n\n";
      continue;
    }
    else{
      int ans = 0;
      vector<tuple<int, int, int>> edges;

      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
          if(AL[i][j] != INF){
            ans++;
            edges.emplace_back(i+1, j+1, AL[i][j]);
          }
        }
      }

      cout << ans << endl;
      for(auto [u, v, w] : edges)
        cout << u << " " << v << " " << w << endl;

      cout << endl;
    }
  }

  return 0;
}
