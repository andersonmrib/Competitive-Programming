#include <bits/stdc++.h>
#define MAX 110
using namespace std;

char grid[MAX][MAX];
int visited[MAX][MAX];

int main(){

  int x, y; cin >> x >> y;

  for(int i=0; i<y; i++)
    for(int j=0; j<x; j++)
      cin >> grid[i][j];

  int moveVer = 0, moveHor = 0, i = 0, j = 0; // vertically and horizontally
  bool chestFound = false;
  memset(visited, 0, sizeof visited);

  while(true){

    if(visited[i][j] || (i < 0) || (i >= y) || (j < 0) || (j >= x))
      break;
    visited[i][j] = 1;

    if(grid[i][j] == '>'){
      moveHor = 1;
      moveVer = 0;
    }
    if(grid[i][j] == '<'){
      moveHor = -1;
      moveVer = 0;
    }
    if(grid[i][j] == '^'){
      moveHor = 0;
      moveVer = -1;
    }
    if(grid[i][j] == 'v'){
      moveHor = 0;
      moveVer = 1;
    }
    if(grid[i][j] == '*'){
      chestFound = true;
      break;
    }
    i += moveVer, j += moveHor;
  }

  if(chestFound) cout << "*\n";
  else           cout << "!\n";

  return 0;
}
