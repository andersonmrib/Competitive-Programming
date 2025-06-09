#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

// Spoiler at the end of the file!

int W, H, ans;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
char grid[55][55];

void floodfill(int r, int c){
  if((r < 0) || (r >= H) || (c < 0) || (c >= W)) return;
  if(grid[r][c] == 'T' || grid[r][c] == '#') return;
  if(grid[r][c] == 'g'){
    ans++;
    grid[r][c] = '#';
    return;
  }
  if(grid[r][c] == 'G') ans++;
  grid[r][c] = '#';
  for(int d=0; d<4; d++)
    floodfill(r+dr[d], c+dc[d]);
}

int main(){

  while(cin >> W >> H){

    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++)
        cin >> grid[i][j];

    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++)
        if(grid[i][j] == 'T'){
          for(int d=0; d<4; d++){
            int nr = i+dr[d], nc = j+dc[d];
              if((nr < 0) || (nr >= H) || (nc < 0) || (nc >= W)) continue;
              if(grid[nr][nc] == 'G') grid[nr][nc] = 'g';
              else if(grid[nr][nc] != 'g' && grid[nr][nc] != 'T') grid[nr][nc] = '#';
          }
        }

    ans = 0;
    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++)
        if(grid[i][j] == 'P')
          floodfill(i, j);

    cout << ans << endl;
  }
  return 0;
}

// It happens that when you first "feel" the presence of a trap,
// you can pick up a coin when standing on it, since you did not know
// there was a trap there!
// Just check the for starting at line 37.

// Not a really good problem in my opinion...
// Could have been written better.
