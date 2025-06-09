#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char grid[150][150];
int R, C;

int dr[] = {1, 0, -1, 0};                                // in order: S/E/N/W
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c, char c1){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // out of the grid
  if(grid[r][c] != c1) return;
  grid[r][c] = '.';                                      // does not have the color we want
  for(int d=0; d<4; d++)                                 // begins to explore
    floodfill(r+dr[d], c+dc[d], c1);                     // all 4 directions
}

int main(){

  int numCases = 0;

  while(cin >> R >> C){

    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        cin >> grid[i][j];

    int ans = 0;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
          if(grid[i][j] == '-'){
             ans++;
             floodfill(i, j, '-');
          }
       }
    }
    printf("Case %d: %d\n", ++numCases, ans);
  }

  return 0;
}
