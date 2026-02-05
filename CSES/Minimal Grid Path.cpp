#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;

  int n; cin >> n;
  vector<string> grid;
  for(int i=0; i<n; i++){
    string line; cin >> line;
    grid.push_back(line);
  }

  string ans;
  ans += grid[0][0];

  vector<pair<int, int>> cur;
  cur.push_back({0, 0});

  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vis[0][0] = true;

  for(int k=1; k<=2*n-2; k++){

    char best = 'Z';
    vector<pair<int, int>> next;
    for(auto [x, y] : cur){
      if(x+1 < n) best = min(best, grid[x+1][y]);
      if(y+1 < n) best = min(best, grid[x][y+1]);
    }

    for(auto [x, y] : cur){
      if(x+1 < n && grid[x+1][y] == best && !vis[x+1][y]){
        vis[x+1][y] = true;
        next.push_back({x+1, y});
      }
      if(y+1 < n && grid[x][y+1] == best && !vis[x][y+1]){
        vis[x][y+1] = true;
        next.push_back({x, y+1});
      }
    }

    ans += best;
    cur.swap(next);
  }

  cout << ans << endl;

  return 0;
}
