#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<string> grid;
int ans, M, N;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool reachable(int x, int y){
  return (x >= 0 && x < M && y >= 0 && y < N);
}
void floodfill(int i, int j){
  if(!reachable(i, j)) return;
  if(grid[i][j] != '0') return;
  grid[i][j] = '1';
  ans++;
  for(int d=0; d<4; d++)
    floodfill(i+dr[d], j+dc[d]);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int x, y; cin >> x >> y;
    x--, y--;
    cin.ignore();

    grid.clear();
    while(true){  // 0 = water, 1 = land
      string line;
      getline(cin, line);
      if(line == "") break;
      grid.push_back(line);
    }

    ans = 0;
    M = grid.size(), N = grid[0].size();
    floodfill(x, y);
    cout << ans << "\n";

    if(t) cout << "\n";
  }

  return 0;
}
