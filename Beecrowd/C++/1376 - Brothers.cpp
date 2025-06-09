#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

// A little bit of flood and fill techniques...
bool isPossible(int r, int c, int R, int C){
  if(r >= 0 && r < R && c >= 0 && c < C)
    return true;
  return false;
}

int main(){

  speedBoost;
  int N, R, C, K;
  while((cin >> N >> R >> C >> K), (N || R || C || K)){

    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<int>> tempGrid(R, vector<int>(C));

    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        cin >> grid[i][j];

    for(int k=0; k<K; k++){
      tempGrid = grid;

      for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
          for(int d=0; d<4; d++){
            int nr = i + dr[d];
            int nc = j + dc[d];

            if(isPossible(nr, nc, R, C)){
              if((grid[i][j] + 1) % N == grid[nr][nc])
                tempGrid[nr][nc] = grid[i][j];
            }
          }
        }
      }
      grid = tempGrid;
    }

    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        if(j > 0) cout << " ";
        cout << grid[i][j];
      }
    cout << "\n";
    }
  }

  return 0;
}
