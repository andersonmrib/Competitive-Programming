#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char line[150], grid[150][150];
int R, C;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1}; // in order> S/SE/E/NE/N/NW/W/SW
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; // just shift the whole array for the right

int floodfill(int r, int c, char c1, char c2){ // returns the size of CC
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return 0; // outside grid
  if(grid[r][c] != c1) return 0; // does not have color c1
  int ans = 1;                   // (r,c) has color c1
  grid[r][c] = c2;               // avoid cycling
  for(int d=0; d<8; d++)
    ans += floodfill(r+dr[d], c+dc[d], c1, c2); // calls floodfill exploring
  return ans;                                   // all 8 directions
}

int main(){

  int n; sscanf(gets(line), "%d", &n);
  gets(line);

  while(n--){
    R = 0;
    while(1){
      gets(grid[R]);
      if((grid[R][0] != 'L') && (grid[R][0] != 'W')) break;
      ++R;
    }
    C = (int)strlen(grid[0]);

    strcpy(line, grid[R]); // contains the last line with coordinates
    while(1){
        int row, col; sscanf(line, "%d %d", &row, &col), row--; col--;
        printf("%d\n", floodfill(row, col, 'W', '.'));
        floodfill(row, col, '.', 'W'); // restores floodfill for the next call
        gets(line);
        if(strcmp(line, "") == 0 || feof(stdin))
            break;

    }
        if(n) cout << endl; //! - careful with PE - !
  }

  return 0;
}
