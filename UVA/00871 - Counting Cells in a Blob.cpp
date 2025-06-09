#include <bits/stdc++.h>
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char line[25], grid[25][25];
int R, C;

int floodfill(int r, int c){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return 0;
  if(grid[r][c] != '1') return 0;  // does not have the right color
  int blob = 1;                    // going to find biggest size
  grid[r][c] = '.';                // colored
  for(int d=0; d<8; d++)
    blob += floodfill(r + dr[d], c + dc[d]);
  return blob;
}

int main(){

  int TC; cin >> TC;
  cin.ignore();
  gets(line);

  bool first = true;

  while(TC--){

    if(!first) gets(line);

    R = 0;
    while(1){
      gets(grid[R]);
      if((grid[R][0] != '1') && (grid[R][0] != '0'))
        break;
      R++;
    }
    C = (int)strlen(grid[0]);

    int ans = 0;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        if(grid[i][j] == '1'){
          int ctt = floodfill(i, j);
          ans = max(ans, ctt);
        }
      }
    }
    cout << ans << endl;
    if(TC) cout << endl;
  }

  return 0;
}
