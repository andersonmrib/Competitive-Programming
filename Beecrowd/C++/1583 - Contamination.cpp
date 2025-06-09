#include <bits/stdc++.h>
using namespace std;

#define MAX 60
char grid[MAX][MAX];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int R, C;

void floodfill(int r, int c){
  if((r < 0) || (r >= R) || (c < 0) || (c >= C)) return;
    if(grid[r][c] == 'X' || grid[r][c] == 'T') return;

  grid[r][c] = 'T';

  for(int d=0; d<4; d++)
    floodfill(r+dr[d], c+dc[d]);
}

int main(){

  while ((cin >> R >> C), R, C){

    cin.ignore();
    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        cin >> grid[i][j];

    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        if(grid[i][j] == 'T'){
          grid[i][j] = 'A';
          floodfill(i, j);
        }
      }
    }

    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }

    return 0;
}
