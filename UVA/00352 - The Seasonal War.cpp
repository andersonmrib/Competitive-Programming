#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char grid[150][150];
int D; // dimension

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1 };                 // in order: S/SE/E/NE/N/NW/W/SW
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1 };

void floodfill(int r, int c, char c1){
  if((r < 0) || (r >= D) || (c < 0) || (c >= D)) return; // out of the grid
  if(grid[r][c] != c1) return;                           // does not have the color we want
  grid[r][c] = '.';
  for(int d=0; d<8; d++)                                 // begins to explore
    floodfill(r+dr[d], c+dc[d], c1);                     // all 8 directions
}

int main(){

  int numCases = 0;
  while(cin >> D){

    for(int i=0; i<D; i++)
      for(int j=0; j<D; j++)
        cin >> grid[i][j];

    int ans = 0;
    for(int i=0; i<D; i++){
      for(int j=0; j<D; j++){
          if(grid[i][j] == '1'){
             ans++;
             floodfill(i, j, '1');
          }
       }
    }
    printf("Image number %d contains %d war eagles.\n", ++numCases, ans);
  }


  return 0;
}
