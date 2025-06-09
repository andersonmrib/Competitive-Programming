#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int M, N;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

  speedBoost;
  cin >> M >> N;

  char grid[M][N];
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      cin >> grid[i][j];

  int ans = 0;
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){

      if(grid[i][j] == '#'){

        bool isCosta = false;
        for(int d=0; d<4; d++){
          int nr = i + dr[d];
          int nc = j + dc[d];

          if(nr < 0 || nr >= M || nc < 0 || nc >= N || grid[nr][nc] == '.'){
            isCosta = true;
            break;
          }
        }

        if(isCosta) ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
