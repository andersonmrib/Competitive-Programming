#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N; cin >> N;
  while(N--){

    int grid[9][9];
    memset(grid, 0, sizeof grid);
    for(int i=0; i<9; i+=2){
      for(int j=0; j<=i; j+=2){
        cin >> grid[i][j];
      }
    }

    for(int i=8; i>0; i-=2){
      for(int j=0; j<i; j+=2){
        grid[i][j+1] = (grid[i-2][j] - grid[i][j] - grid[i][j+2])/2;
        grid[i-1][j] = grid[i][j] + grid[i][j+1];
        grid[i-1][j+1] = grid[i][j+1] + grid[i][j+2];
      }
    }

    for(int i=0; i<9; i++){
      for(int j=0; j<=i; j++){
        if(j == 0) cout << grid[i][j];
        else       cout << " " << grid[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
