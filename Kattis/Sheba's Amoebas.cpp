#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char grid[150][150];
int R, C;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1 };                 // in order: S/SE/E/NE/N/NW/W/SW
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1 };

void floodfill(int r, int c, char c1){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // out of the grid
  if(grid[r][c] != c1) return;                           // does not have the color we want
  grid[r][c] = '.';
  for(int d=0; d<8; d++)                                 // begins to explore
    floodfill(r+dr[d], c+dc[d], c1);                     // all 8 directions
}

int main(){

  cin >> R >> C;

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      cin >> grid[i][j];

  int ans = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
        if(grid[i][j] == '#'){
           ans++;
           floodfill(i, j, '#');
        }
     }
  }
  cout << ans << endl;

  return 0;
}
