#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int r, c;
int starSize;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char grid[102][102];

void floodfill(int row, int col){
  if((row < 0) || (row >= r) || (col < 0) || (col >= c)) return;
  if(grid[row][col] == '.') return;
  grid[row][col] = '.';
  starSize++;
  for(int d=0; d<8; d++)
    floodfill(row+dr[d], col+dc[d]);
}

int main(){

  while((cin >> r >> c), (r || c)){

    for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
        cin >> grid[i][j];

    int ans = 0;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(grid[i][j] == '*'){
          starSize = 0;
          floodfill(i, j);
          if(starSize == 1) ans++;
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
