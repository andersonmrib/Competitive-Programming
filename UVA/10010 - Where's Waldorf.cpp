#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
      cin >> grid[i];
      transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::tolower);
    }

    int q; cin >> q;
    while(q--){

      string w; cin >> w;
      transform(w.begin(), w.end(), w.begin(), ::tolower);

      bool found = false;

      for(int i=0; i<n && !found; i++){
        for(int j=0; j<m && !found; j++){
          for(int d=0; d<8; d++){
            int x = i, y = j, idx = 0;

            while(idx < w.size()){
              if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != w[idx])
                break;
              idx++;                  // Match!
              x += dr[d], y += dc[d]; // Find another one!
            }

            if(idx == w.size()){
              cout << i + 1 << " " << j + 1 << "\n";
              found = true;
              break;
            }
          }
        }
      }
    }

    if(t) cout << "\n";
  }

  return 0;
}
