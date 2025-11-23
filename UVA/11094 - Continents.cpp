#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<string> grid;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool inside(int r, int c){
  return r >= 0 && r < n && c >= 0 && c < m;
}

int floodfill(int r, int c, char landChar){

  if(c < 0)  c = m-1;
  if(c >= m) c = 0;

  if(!inside(r, c)) return 0;
  if(grid[r][c] != landChar) return 0;
  grid[r][c] = '.';

  int ctt = 1;
  for(int d=0; d<4; d++)
    ctt += floodfill(r + dr[d], c + dc[d], landChar);

  return ctt;
}

int main(){

  speedBoost;
  while(cin >> n >> m){

    grid.resize(n);
    for(int i=0; i<n; i++)
      cin >> grid[i];

    int x, y; cin >> x >> y;
    char landChar = grid[x][y];
    floodfill(x, y, landChar);

    int biggestRegion = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j] == landChar){
          int curSize = floodfill(i, j, landChar);
          if(curSize > biggestRegion)
            biggestRegion = curSize;
        }
      }
    }

    cout << biggestRegion << endl;
  }

  return 0;
}
